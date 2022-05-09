#include "wordle_Setup.h"
#include "singleton.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void wordle_Setup::import_Words() {
    ifstream list;
    list.open("Scrabble list.txt", ios::in | ios:: binary);
    string line = "abcdef";
	//string* temp;
	if(list.is_open() ){

			while(getline(list, line)){
			cout << line << endl;
			Singleton::getInstance()->getlists()->word_List.push_back(line);
			}

        }

	else
		cout << "error message" << endl;
	list.close();
	return;
}

void wordle_Setup::value_Letters(){

	for(long unsigned i = 0; i < Singleton::getInstance()->getlists()->word_List.size(); i++){
		for(int j = 0; j < 5; j++){
			string tempw = Singleton::getInstance()->getlists()->word_List[i];
			char tempc = tempw[j];
			Singleton::getInstance()->getlists()->letter_Values[j][tempc - 97]++;
		}
	}

	return;
}
