#ifndef SINGLETON_H
#define SINGLETON_H
#include "wordle_Setup.h"
#include  <string>

using namespace std;

class Singleton{

  public:
        static Singleton *getInstance();
        ~Singleton();
        vector<string>* getwordlist();
	vector<string>* getwordlesolutions();
  private:
        Singleton(){};
        vector<string>* word_List;
	vector<string>* wordle_Solutions;
        static Singleton *instance;
};
#endif
