#include "lists.h"
#include "singleton.h"

Lists::Lists(){

    for(int i = 0; i < 26; i++){
        for(int j  = 0; j < 5; j++){
            this->letter_Values[j][i] = 0;
        }
    }
    
};