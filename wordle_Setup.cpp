#include "wordle_Setup.h"
#include "singleton.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void wordle_Setup::import_Words() {
	ifstream solutions;
	solutions.open("Wordle list.txt", ios::in | ios:: binary);
    ifstream list;
    list.open("Scrabble list.txt", ios::in | ios:: binary);
    string line = "abcdef";
	//string* temp;
	if(list.is_open() ){
		while(getline(list, line)){
		//cout << line << endl;
		Singleton::getInstance()->getlists()->word_List.push_back(line);
		}

    }

	else{
		cout << "Scrabble list textfile failed to open" << endl;
		list.close();
		return;
	}
	if(solutions.is_open() ){
		while (getline(solutions, line)){
        	std::stringstream ss(line);
        	while(getline(ss, line, ' ')){
            	if(line.length() == 6 | line.length() == 5){
					for(int i = 0; i < line.length(); i++){
						line[i] = tolower(line[i]);
					}
					Singleton::getInstance()->getlists()->wordle_Solutions.push_back(line);
            	}
        	}
    	}
    }
		
	else{
		cout << "Wordle answers list textfile failed to open" << endl;
		solutions.close();
		return;
	}
	solutions.close();
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

void wordle_Setup::order_Words() {
	
	int value;
	string tempw;
	for(long unsigned i = 0; i < Singleton::getInstance()->getlists()->word_List.size(); i++){
		tempw = Singleton::getInstance()->getlists()->word_List[i];
		value = 0;
		for(int j = 0; j < 5; j++){
			char tempc = tempw[j];
			value = value + Singleton::getInstance()->getlists()->letter_Values[j][tempc - 97];
		}
		Singleton::getInstance()->getlists()->letter_Values_vec.push_back(value);
	}
	/*for(long unsigned i = 0; i < letter_Values_vec.size(); i++)
		cout << i << " " << letter_Values_vec[i] << endl;

	return;*/
}