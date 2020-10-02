#include <iostream>
#include "../include/ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

NoDuplo* ListaDupla::get(int k)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }

    return p;

}

void ListaDupla::imprime()
{
   if(primeiro != NULL){
        bool first = true;
        for(NoDuplo *p = primeiro; p!=NULL ; p=p->getProx() ){
            if(first){
                first = false;
                cout << p->getInfo();
            }
            else
                cout << " - " << p->getInfo();
        }
        cout<<endl;
   }
   else cout << "Vazio" << endl;

}

/**
 * Insere o valor passado por parametro no final da lista encadeada
 * @param val valor a ser adicionado
 */
NoDuplo * ListaDupla::insereFinal(int val){
    NoDuplo *n = new NoDuplo;
    n->setInfo(val);
    n->setAnt(ultimo);
    n->setProx(NULL);

    if(this->n==0) primeiro = n;
    else ultimo->setProx(n);

    ultimo = n;
    this->n++;
    return n;
}





