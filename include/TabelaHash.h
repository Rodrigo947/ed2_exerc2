#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

#include <iostream>
#include <math.h>
#include <vector>
#include "ListaDupla.h"

using namespace std;

class TabelaHash
{
private:
    char function_hash_type;
    int m;
    int colisoes;
    vector<int> dadosEscolhidos;
    vector<ListaDupla*> tabela;
public:
    TabelaHash();
    int hashDivisao(int k);
    int hashMultiplicacao(int k);
    int minhaHash(int k);
    
    void create(int m, char function_hash_name);
    void destroy();
    NoDuplo* insert(int key, int data);
    NoDuplo* lookup(int key, int data);
    
    int getColisoes();
    void imprimeTabela();
};

#endif