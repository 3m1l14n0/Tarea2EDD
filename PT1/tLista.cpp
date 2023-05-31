#include "tLista.hpp"


ListaEnlazada::ListaEnlazada(){
    pos = 0;
    listsize = 0;
    head = tail = curr = new Nodos;
}

ListaEnlazada::~ListaEnlazada(){
    delete[] head;
}

void ListaEnlazada::INTERCAMBIAR(tElemLista n){
    Nodos* newNodo = new Nodos;
    newNodo->data = n;
    newNodo->sig = curr->sig->sig;
    delete[] curr->sig;
    curr->sig = newNodo;
}

int ListaEnlazada::INSERTAR(tElemLista n){
    Nodos* nuevonodo = new Nodos;
    nuevonodo->sig = curr -> sig;
    curr->sig = nuevonodo; 
    nuevonodo->data = n;
    listsize++;
    return pos;
}

void ListaEnlazada::BORRAR(){
    Nodos* aux = curr->sig->sig;
    delete[] curr->sig;
    curr->sig=aux;
    listsize--;
}

void ListaEnlazada::moveToPos(int i){
    curr = head;
    pos = 0;
    while (pos < i){
        curr = curr->sig;
        pos+=1;
    }
    
}

int ListaEnlazada::append(tElemLista item){
    Nodos* newNodo = new Nodos;
    newNodo->data = item;
    tail->sig = newNodo;
    tail = tail->sig;
    listsize++;
    return (listsize-1);
}

tElemLista ListaEnlazada::getValue(){
    return curr->sig->data;
}

int ListaEnlazada::length(){
    return listsize;
}

void ListaEnlazada::clear(){
    while(listsize>0){
        Nodos* aux = head->sig;
        delete[] head;
        head = aux;
        listsize--;
    }

}