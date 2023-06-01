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
        ~tABB();
        void insert(tElem item);
        bool find(tElem item);
        int lower_bound(tElem item);
        int inOrdenCont(); // Cuenta los elementos del arbol
};