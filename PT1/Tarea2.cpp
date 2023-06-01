#include <iostream>
#include <string>
#include <fstream>
#include "tLista.cpp"

using namespace std;

void EscribirArchivo(ListaEnlazada* SecModificada){
    fstream output;
    output.open("secuencias-reconstruidas.txt", ios::app);
    for(int i = 0; i < SecModificada->length(); i++){
        SecModificada->moveToPos(i);
        output << SecModificada->getValue();
    }
    output << "\n";
    output.close();
}


int main(){
    fstream input;
    input.open("secuencias-nucleotidos.txt", ios::in);
    if(!input.is_open()){
        cout << "Error al abrir el archivo \"secuencias-nucleotidos.txt\"\n";
        exit(1);
    }
    int lenSec, cantidadSec;
    string sec;
    input >> lenSec >> sec >> cantidadSec;
    for(int i = 0; i < cantidadSec; i++){
        int pos;
        tElemLista n;
        ListaEnlazada Secuencia;
        for(int j = 0; j < lenSec; j++){
            Secuencia.moveToPos(j);
            Secuencia.INSERTAR(sec[j]);
        }
        int cantMod;
        input >> cantMod;
        for(int j = 0; j < cantMod; j++){
            string modificacion;
            input >> modificacion;
            if(modificacion == "INSERTAR"){
                input >> pos >> n;
                Secuencia.moveToPos(pos);
                Secuencia.INSERTAR(n);
            }
            if(modificacion == "INTERCAMBIAR"){
                input >> pos >> n;
                Secuencia.moveToPos(pos);
                Secuencia.INTERCAMBIAR(n);
            }
            if(modificacion == "BORRAR"){
                input >> pos;
                Secuencia.moveToPos(pos);
                Secuencia.BORRAR();
            }
        }
        EscribirArchivo(&Secuencia);
    }

    input.close();
    return 0;
}