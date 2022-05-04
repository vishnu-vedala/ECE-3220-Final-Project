#include "word_Setup.h"
#include "singleton.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void import_Words() {
        ifstream list;
        list.open("Scrabble list.txt", ios::in | ios:: binary);
        string line;
	if(student.is_open() ){
                while(getline(list, line))
			Singleton::getInstance()->word_List.pushback(line);
        }
	else
		cout<<"error message"<<endl;
	student.close();

	return;

}

void value_Letters(){

	string tempw, temp1, temp2, temp3, temp4, temp5;

	for(int i = 0; i < Singleton::getInstance()->word_List.size(); i++){
		tempw = Singleton::getInstance()->word_List[i];
		temp1 = temp1 + tempw[0];
		temp2 = temp2 + tempw[1];
		temp3 = temp3 + tempw[2];
		temp4 = temp4 + tempw[3];
		temp5 = temp5 + tempw[4];
	}

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 26; j++{
			get_letter_values(i, j) = count(temp1.begin(), j + 21);
		}
	}
	return;

}
