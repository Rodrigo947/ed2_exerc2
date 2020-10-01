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

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
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

void ListaDupla::set(int k, int val)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
	NoDuplo *p = new NoDuplo();
	p->setInfo(val);
	p->setProx(primeiro);
	p->setAnt(NULL);

	if(n == 0) ultimo = p;
	else primeiro->setAnt(p);

	primeiro = p;
	n = n + 1;
}

void ListaDupla::removeInicio()
{
	NoDuplo *p;
	if(primeiro != NULL)
	{
		p = primeiro;
		primeiro = p->getProx();
		delete p;
		n = n - 1;

		if(n == 0) 	ultimo = NULL;
		else primeiro->setAnt(NULL);
	}
	else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::imprime()
{
   if(primeiro != NULL){
        for(NoDuplo *p = primeiro; p!=NULL ; p=p->getProx() ){
            cout << p->getInfo() << ",";
        }
        cout<<endl;
   }
   else cout << "ERRO: lista vazia" << endl;
}


void ListaDupla::imprimeReverso()
{
   if(primeiro != NULL){
        for(NoDuplo *p = ultimo; p!=NULL ; p=p->getAnt() ){
            cout << p->getInfo() << ",";
        }
        cout<<endl;
   }
   else cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::insereFinal(int val){
    NoDuplo *n = new NoDuplo;
    n->setInfo(val);
    n->setAnt(ultimo);
    n->setProx(NULL);

    if(this->n==0) primeiro = n;
    else ultimo->setProx(n);

    ultimo = n;
    this->n++;
}

void ListaDupla::removeFinal(){
    if(ultimo==NULL) cout << "ERRO: lista vazia" << endl;
    else{
        NoDuplo *n = ultimo;
        ultimo = n->getAnt();
        delete n;
        this->n--;

        if(this->n==0) primeiro = NULL;
        else ultimo->setProx(NULL);
    }

}



