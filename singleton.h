#ifndef SINGLETON_H
#define SINGLETON_H
#include "wordle_Setup.h"
#include "lists.h"
#include <string>

using namespace std;

class Singleton{

  public:
        static Singleton *getInstance();
        Lists* getlists();
        
  private:
        Singleton(){};
        static Singleton *instance;
        Lists* lists;
        
};
#endif
