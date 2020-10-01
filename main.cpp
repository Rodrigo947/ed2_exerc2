#include <iostream>
#include "include/TabelaHash.h"

using namespace std;

int main(int arc, char* argv[])
{
	cout<<"Tabela Hash"<<endl;
	TabelaHash *th = new TabelaHash();

	th->create(20,'d');
	
}

