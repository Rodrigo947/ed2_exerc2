#ifndef LISTADUPLA_H_INCLUDED
#define LISTADUPLA_H_INCLUDED
#include "NoDuplo.h"

class ListaDupla
{
public:
    ListaDupla();
    ~ListaDupla();
    NoDuplo* get(int k);
    NoDuplo * insereFinal(int val);       
    void imprime();

private:
    NoDuplo *primeiro;
    NoDuplo *ultimo;
    int *n;
};
#endif
