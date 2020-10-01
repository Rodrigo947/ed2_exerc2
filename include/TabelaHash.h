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
    vector<ListaDupla> tabela;
public:

    TabelaHash();
    int hashDivisao(int k, int m);
    int hashMultiplicacao(int k, int m);
    int minhaHash(int k, int m);
    
    void create(int m, char function_hash_name);
    NoDuplo* insert(int key, int data);
    int* lookup(int key, int data);
    
    void destroy();
};



#endif