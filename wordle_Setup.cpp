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
    string line;
	if(list.is_open() ){
                while(getline(list, line))
			Singleton::getInstance()->getlists().word_List->push_back(line);
        }
	else
		cout << "error message" << endl;
	list.close();
	return;
}

void wordle_Setup::value_Letters(){

	string tempw, temp1, temp2, temp3, temp4, temp5;

	vector<string> templ = *Singleton::getInstance()->getlists().word_List;

	for(long unsigned i = 0; i < Singleton::getInstance()->getlists().word_List->size(); i++){

		tempw = templ[i];
		temp1 = temp1 + tempw[0];
		temp2 = temp2 + tempw[1];
		temp3 = temp3 + tempw[2];
		temp4 = temp4 + tempw[3];
		temp5 = temp5 + tempw[4];
	}

	//for(int i = 0; i < 5; i++){
		for(int j = 0; j < 26; j++){
			int count = 0;
			int size = temp1.size();
			for(int i = 0; i < size; i++){
				if(temp1[j] == j+21)
				count++;
		
			}
		Singleton::getInstance()->getlists().letter_Values[1][j] = count;

			//Singleton::getInstance()->get_letter_Values(1, j) = count(temp1[0], temp1[temp1.size()], j + 21);
		}
	//}
	return;

}
