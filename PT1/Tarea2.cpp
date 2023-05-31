#include <iostream>
#include <string>
#include <fstream>
#include "tLista.cpp"

using namespace std;

void EscribirArchivo(ListaEnlazada SecModificada){
    fstream output;
    output.open("secuencias-reconstruidas.txt", ios::app);
    for(int i = 0; i < SecModificada.length(); i++){
        SecModificada.moveToPos(i);
        output << SecModificada.getValue();
    }
    output << "\n";
    output.close();
}



int main(){
    
    ListaEnlazada SecuenciaBase;
    fstream input;
    input.open("secuencias-nucleotidos.txt", ios::in);
    if(!input.is_open()){
        cout << "Error al abrir el archivo \"secuencias-nucleotidos.txt\"\n";
        exit(1);
    }
    int lenSec, cantSec;
    input >> lenSec;
    for(int i = 0; i < lenSec; i++){
        tElemLista elemSec;
        input >> elemSec;
        SecuenciaBase.append(elemSec);
    }
    input >> cantSec;
    int pos;
    tElemLista n;
    for(int i = 0; i < cantSec; i++){
        ListaEnlazada SecModificada;
        for(int j = 0; j < SecuenciaBase.length(); j++){
            SecuenciaBase.moveToPos(j);
            SecModificada.append(SecuenciaBase.getValue());
        }
        int cantMod;
        input >> cantMod;
        for(int j = 0; j < cantMod; j++){
            string mod;
            input >> mod;
            if(mod == "INSERTAR"){
                input >> pos >> n;
                SecModificada.moveToPos(pos);
                SecModificada.INSERTAR(n);
            }
            else if(mod == "INTERCAMBIAR"){
                input >> pos >> n;
                SecModificada.moveToPos(pos);
                SecModificada.INTERCAMBIAR(n);
            }
            else if(mod == "BORRAR"){
                input >> pos;
                SecModificada.moveToPos(pos);
                SecModificada.BORRAR();
            }
        }
        EscribirArchivo(SecModificada);
    }
    input.close();
    return 0;
}
