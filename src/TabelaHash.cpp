#include "../include/TabelaHash.h"

TabelaHash::TabelaHash(){
    this->m = 0;
    this->colisoes = 0;
}

int TabelaHash::hashDivisao(int k){
	return fmod(k,m);
}

int TabelaHash::hashMultiplicacao(int k){
	float a = (sqrt(5)-1)/2;
	float calc = m*( fmod(k*a,1) );
	return floor( calc );
}
/**
 * Método Escolhido: Transformação de raiz + 
 * uso do constante "a" na divisão
 * 
 */
int TabelaHash::minhaHash(int k){
    string restos,base9;
    float multiplicacao,divisao;
    float a = (sqrt(5)-1)/2;
    if(k==0){
        restos = to_string(0);
    }
    else{
        while (k!=0)
        {
            restos += to_string(k % 9);
            k = k / 9;  
        }
    }

    //Invertendo a sequencia de restos
    for (int i = restos.size()-1; i >= 0 ; i--)
        base9 += restos[i];
    
    //Multiplicando a constante A com o numero convertido para a base
    multiplicacao = stoi(base9)*a;
    //Aplicando o hash da divisao
    divisao = fmod(multiplicacao,m);

	return floor( divisao );
}

/**
 * Cria uma tabela de tamanho m que usa a função hash
 * @param m tamanho da tabela
 * @param function_hash_name tipo da função hash /
 * Divisao = d /
 * Multiplicacao = m /
 * Minha Hash = qualquer outro valor /
 */
void TabelaHash::create(int m, char function_hash_type){
    destroy();
    this->m = m;
    this->function_hash_type = function_hash_type;
    this->colisoes = 0;
    //Inicializando tabela hash com valores nulos
    for (int i = 0; i < m; i++)
    {
        ListaDupla *ld = new ListaDupla();
        tabela.push_back(ld);    
    }
}

void TabelaHash::destroy(){
    if(m!=0){
        //Deletando as listas duplamente encadeadas de cada posição do vetor
        for (int i = 0; i < m; i++)
        {
           delete tabela[i];    
        }
        //limpando o vetor e zerando as variaveis
        tabela.clear(); 
        this->m = 0;
        this->function_hash_type = ' ';
        this->colisoes = 0;
        this->dadosEscolhidos.clear();
    }
    
}

NoDuplo* TabelaHash::insert(int key, int data){
    int posicao;
    if (m == 0) return NULL; //Se a tabela não foi criada não insere 
    dadosEscolhidos.push_back(data);

    switch (function_hash_type)
    {
    case 'd':
        posicao = hashDivisao(key);
        break;
    
    case 'm':
        posicao = hashMultiplicacao(key);
        break;

    default:
        posicao = minhaHash(key);  
        break;
    }

    int i = 0;
    //Só irá addicionar um novo valor se o mesmo não existir na tabela
    if(lookup(key,data)==NULL){
        //Contabilizado possiveis colisões caso o valor não esteja na tabela
        while (tabela[posicao]->get(i)!=NULL)
        {
            this->colisoes++;
            i++;
        }
        return tabela[posicao]->insereFinal(data);
    }
    return NULL;
    
}

NoDuplo* TabelaHash::lookup(int key, int data){
    int posicao;
    if (m == 0) return NULL; //Caso a tabela ainda não foi criada
    switch (function_hash_type)
    {
    case 'd':
        posicao = hashDivisao(key);
        break;
    
    case 'm':
        posicao = hashMultiplicacao(key);
        break;

    default:
        posicao = minhaHash(key);  
        break;
    }

    int i=0;
    NoDuplo* no = tabela[posicao]->get(i);
    while(no!=NULL)
    {
        if(no->getInfo() == data)
            return no;
        i++;
        no = tabela[posicao]->get(i);
    }

    return no;
    
}

int TabelaHash::getColisoes(){ return colisoes; }

void TabelaHash::imprimeTabela(){ 

    cout << "Vetor de numeros escolhidos randomicamente: ";
    for (int i = 0; i < dadosEscolhidos.size(); i++)
    {
        cout << dadosEscolhidos[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        cout << "Posicao " << i << " -> ";
        tabela[i]->imprime();
    }
    cout<<endl;
    cout << "Colisoes: " << colisoes << endl;
    
}
