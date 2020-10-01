#ifndef LISTADUPLA_H_INCLUDED
#define LISTADUPLA_H_INCLUDED
#include "NoDuplo.h"

class ListaDupla
{
public:
    ListaDupla();
    ~ListaDupla();
    bool busca(int val);
    NoDuplo* get(int k);
    void set(int k, int val);
    void insereInicio(int val);
    void removeInicio();
    void insereFinal(int val); 
    void removeFinal();        
    void imprime();
    void imprimeReverso();

private:
    NoDuplo *primeiro;
    NoDuplo *ultimo;
    int *n;
};
#endif
