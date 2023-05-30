#include "tABB.hpp"

tABB LucesEnc;

void ENCENDER(int i){
    if(LucesEnc.find(i) == true) return;
    LucesEnc.insert(i);
}

void CUANTOS_ENCENDER(int i){
    int low = LucesEnc.lower_bound(i);
    int cantOff = 0;
    if(low == -1){
        for(int j = 0; j <= i; j++){
            if(!LucesEnc.find(j)){
                cantOff++;
            }
        }
        cout << cantOff << endl;
        return;
    }
    for(int j = low; j <= i; j++){
        if(!LucesEnc.find(j)){
                cantOff++;
            }
    }
    cout << cantOff << endl;
}

void PARAR_PROGRAMA(){
    cout << LucesEnc.inOrden() << endl;
}


int main(){
    string func = "";
    int i;
    while(func != "PARAR_PROGRAMA"){
        cin >> func;
        if(func == "ENCENDER"){
            cin >> i;
            ENCENDER(i);
        }
        else if(func == "CUANTOS_ENCENDER"){
            cin >> i;
            CUANTOS_ENCENDER(i);
        }
    }
    PARAR_PROGRAMA();

    return 0;
}