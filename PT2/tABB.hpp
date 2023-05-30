#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef int tElem;

struct tNodoArbolBin{
 tElem info;
 tNodoArbolBin* izq;
 tNodoArbolBin* der;
};


class tABB {
    private:
        tNodoArbolBin* raiz; // puntero al nodo raíz del ABB
        int nElems; // cantidad de elementos en el ABB
    public:
        tABB();
        void insert(tElem item);
        bool find(tElem item);
        int lower_bound(tElem item);
        int inOrden();
};

tABB::tABB(){
    raiz = NULL;
    nElems=0;
}

void inOrdenHelp(tNodoArbolBin *nodo, int &cont) { 
    if(nodo == NULL) return;
    inOrdenHelp(nodo->izq, cont); // visita hijo izquierdo en in-orden
    cont++;
    inOrdenHelp (nodo->der, cont); // visita hijo derecho en in-orden
}

int tABB::inOrden() {
    int cont = 0;
    inOrdenHelp(raiz, cont);
    return cont;
}

void rinsert(tNodoArbolBin* &nodo, tElem item){
    if (nodo == NULL) {
        tNodoArbolBin* newNodo = new tNodoArbolBin;
        newNodo->der = newNodo->izq = NULL;
        newNodo->info = item;
        nodo = newNodo;
        return;
    }
    if (item < nodo->info){
        rinsert(nodo->izq, item);
    }else if (item > nodo->info){
        rinsert(nodo->der, item);
    }
}

void tABB::insert(tElem item){
    rinsert(raiz, item);
    nElems++;
}

// Funcion auxiliar para poder encontrar
bool findHelp(tNodoArbolBin* nodo, tElem item) {
 if (nodo == NULL) return 0; // item no está en el ABB
 if (nodo->info == item) return 1; // item encontrado
 if (item < nodo->info)
 return findHelp(nodo->izq, item);
 else
 return findHelp(nodo->der, item);
}

bool tABB::find(tElem x){
    return findHelp(raiz, x);
}

int rlowerbound(tNodoArbolBin *nodo, tElem item) {
    if (nodo == NULL) return -1;
    else if (nodo->info == item) return item;
    else if (item < nodo->info){
        return rlowerbound(nodo->izq, item);
    }
    else if (item < nodo->der->info){
        return nodo->info;
    }
    else return rlowerbound(nodo->der, item);
}

int tABB::lower_bound(tElem x){
    tNodoArbolBin* curr = raiz;
    tNodoArbolBin* lowerBound = NULL;
    while(curr != NULL){
        if(curr->info <= x){
            lowerBound = curr;
            curr = curr->der;
        }
        else{
            curr = curr->izq;
        }
    }
    if(lowerBound != NULL){
        return lowerBound->info;
    }
    else{
        return -1;
    }
}
