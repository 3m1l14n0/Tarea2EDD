
typedef char tElemLista;

struct Nodos{
    tElemLista data;
    Nodos* sig;
};

//Creamos el TDA de la lista que usaremos y las funciones que nos piden

class ListaEnlazada {
    private:
        Nodos* head;
        Nodos* tail;
        Nodos* curr; //puntero al nodo actual
        unsigned int listsize;
        unsigned int pos;
    public:
        ListaEnlazada();
        ~ListaEnlazada();
        void INTERCAMBIAR(tElemLista n);
        void INSERTAR(tElemLista n);
        void BORRAR();
        void moveToPos(unsigned int pos);
        int append(tElemLista item);
        tElemLista getValue();
        int length();
};

