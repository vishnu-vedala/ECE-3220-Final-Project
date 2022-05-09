#include "singleton.h"
#include "Lists.h"

Singleton *Singleton::instance = NULL;

Singleton *Singleton::getInstance(){

    if(!instance){
        instance = new Singleton();
		instance->lists = new Lists();
    }
    return instance;

}

Lists* Singleton::getlists() {

    return this->lists;

}