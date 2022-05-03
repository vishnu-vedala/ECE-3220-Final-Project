#include "singleton.h"
#include "FileIO.h"

Singleton *Singleton::instance = NULL;

Singleton *Singleton::getInstance(){

        if(!instance){
                instance = new Singleton();

        }
        return instance;

}


vector<string> *Singleton::getwordlist() {

        return word_list;

}

vector<string> *Singleton::getwordlesolutions() {

        return wordle_Solutions;

}
