#include "singleton.h"
#include "Lists.h"

Singleton *Singleton::instance = NULL;

Singleton *Singleton::getInstance(){

        if(!instance){
                instance = new Singleton();
        }
        return instance;

}

/*
void *Singleton::value_Letters(){

	string tempw, temp1, temp2, temp3, temp4, temp5;

	vector<string> templ = *Singleton::getInstance()->getwordlist();

	for(long unsigned i = 0; i < Singleton::getInstance()->getwordlist()->size(); i++){

		tempw = templ[i];
		temp1 = temp1 + tempw[0];
		temp2 = temp2 + tempw[1];
		temp3 = temp3 + tempw[2];
		temp4 = temp4 + tempw[3];
		temp5 = temp5 + tempw[4];
		
	}

		for(int j = 0; j < 26; j++){
			int count = 0;
			int size = temp1.size();
			for(int i = 0; i < size; i++){
				if(temp1 == j + 21)
					count++;
			}
			Singleton::getInstance()->get_letter_Values(1, j) = count;
		}
	
	return;

}
*/


vector<string> *Singleton::getlists() {

        return this->list;

} 