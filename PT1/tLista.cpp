#include "tLista.hpp"

/*****
* ListaEnlazada()
******
* Inicializa la lista enlazada con pos y listsize en 0, se crea un nuevo nodo y sse le aigna a head, tail y curr
******
* Input:
* Sin input
* .......
******
* Returns:
* Sin return
*****/
ListaEnlazada::ListaEnlazada(){
    pos = 0;
    listsize = 0;
    head = tail = curr = new Nodos;
}

/*****
* ~ListaEnlazada()
******
* Destructor de lista enlazada, devuelve la memoria de head.
******
* Input:
* sin input
* .......
******
* Returns:
* sin return
*****/
ListaEnlazada::~ListaEnlazada(){
    curr = head;
    while(curr != NULL){
        Nodos* aux = curr;
        curr = curr->sig;
        delete aux;
    }
}

void ListaEnlazada::INTERCAMBIAR(tElemLista n){
    Nodos* newNodo = new Nodos;
    newNodo->data = n;
    newNodo->sig = curr->sig->sig;
    delete[] curr->sig;
    curr->sig = newNodo;
}

/*****
* int INSERTAR
******
* La funcion inserta el nucleotido (n) entregado mediante el parametro en la posicion en que se encuentra (curr) 
******
* Input:
* tElemLista(char) n : Nucleotido a insertar dentro de la lista
* .......
******
* Returns:
* No return
*****/
void ListaEnlazada::INSERTAR(tElemLista n){
    Nodos* nuevonodo = new Nodos;
    nuevonodo->sig = curr -> sig;
    curr->sig = nuevonodo; 
    nuevonodo->data = n;
    listsize++;
}

void ListaEnlazada::BORRAR(){
    if(curr==NULL || curr->sig == NULL) return;
    Nodos* aux = curr->sig;
    curr->sig=aux->sig;
    delete[] aux;
    listsize--;
}

/*****
* void moveToPos
******
* Mueve el puntero de current(curr) a la posicion seleccionada
******
* Input:
* int i : Posicion a la que se mueve curr
* .......
******
* Returns:
* void, Sin return
*****/

void ListaEnlazada::moveToPos(unsigned int i){
    curr = head;
    pos = 0;
    while (pos < i){
        curr = curr->sig;
        pos+=1;
    }
    
}

/*****
* tElemLista(char) getValue
******
* Retorna el valor de la posicion en que se encuentra
******
* Input:
* Sin input
* .......
******
* Returns:
* tElemLista(char), Retorna el valor de la posicion en que se encuentra
*****/
tElemLista ListaEnlazada::getValue(){
    return curr->sig->data;
}

/*****
* int length
******
* Retorna el largo de la lista
******
* Input:
* Sin input
* .......
******
* Returns:
* int, Largo de la lista enlazada
*****/

int ListaEnlazada::length(){
    return listsize;
}