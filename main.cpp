#include <iostream>
#include "include/TabelaHash.h"

using namespace std;

int main(int arc, char* argv[])
{
	int op=1,m,val,quantNAlet, seed, keyData;
	char hash;
	vector<int> nAleatorios;

	cout<<"------Tabela Hash------"<<endl;
	TabelaHash *th = new TabelaHash();
	NoDuplo *no = new NoDuplo();
	
	while (op!=0)
	{
		cout << "---------Menu---------" << endl;
		cout << "1.Criar Tabela" << endl;
		cout << "2.Inserir valores randomicos" << endl;
		cout << "3.Procurar um dado na tabela" << endl;
		cout << "4.Imprimir tabela" << endl;
		cout << "5.Excluir tabela" << endl;
		cout << "0.Sair" << endl;
		cout << "Escolha uma opcao: ";
		cin >> op;
		cout << endl;
		switch (op)
		{
		case 1:
			cout << "Tamanho da tabela: ";
			cin >> m;
			cout << endl << "Funcoes Hash" << endl;
			cout << "(d).Metodo da divisao " << endl;			
			cout << "(m).Metodo da multiplicacao" << endl;
			cout << "(qualquer outro valor).Minha Hash" << endl;
			cout << "Escolha uma funcao: ";
			cin >> hash;
			th->create(m, hash);
			cout << endl;
			break;
		case 2:
			cout << "Quantidade de valores: ";
			cin >> quantNAlet;
			cout << "Seed: ";
			cin >> seed;
			srand(seed);
			for (int i = 0; i < quantNAlet; i++)
			{
				keyData = rand() % 1000;
				th->insert(keyData,keyData);
			}
			cout << endl;
			break;
		case 3:
			cout << "Valor a ser procurado: ";
			cin >> val;
			no = th->lookup(val,val);
			if(no==NULL)
				cout << "Nao existe o valor na tabela" << endl;
			else
				cout << "O valor esta na tabela" << endl;
			break;
		case 4:
			th->imprimeTabela();
			cout << endl;
			break;
		case 5:
			th->destroy();
			cout << endl;
			break;
		}
	}
	
	
}

