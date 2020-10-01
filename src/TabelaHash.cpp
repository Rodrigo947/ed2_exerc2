#include "../include/TabelaHash.h"

TabelaHash::TabelaHash(){}

int TabelaHash::hashDivisao(int k, int m){
	return fmod(k,m);
}

int TabelaHash::hashMultiplicacao(int k, int m){
	float a = (sqrt(5)-1)/2;
	float calc = m*( fmod(k*a,1) );
	return floor( calc );
}

int TabelaHash::minhaHash(int k, int m){
	float a = (sqrt(5)-1)/2;
	float calc = m*( fmod(k*a,1) );
	return floor( calc );
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
    this->m = m;
    this->function_hash_type = function_hash_type;

    //Inicializando tabela hash com valores nulos
    for (int i = 0; i < m; i++)
    {
        ListaDupla ld;
        tabela.push_back(ld);    
    }
    tabela[0].insereFinal(20);
    if(tabela[0].get(0)==NULL) {
        cout <<"nulo";
    }else  cout <<tabela[0].get(0)->getInfo();
    
}

NoDuplo* TabelaHash::insert(int key, int data){
    int hash;
    switch (function_hash_type)
    {
    case 'd':
        hash = hashDivisao(key,m);
        break;
    
    case 'm':
        hash = hashMultiplicacao(key,m);
        break;

    default:
        hash = minhaHash(key,m);  
        break;
    }
}