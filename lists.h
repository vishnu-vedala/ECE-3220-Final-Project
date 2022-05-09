#ifndef LISTS_H
#define LISTS_H


#include <vector>
#include <string>
#include <algorithm>


using namespace std;


class Lists{

public :
    int letter_Values[5][26] = { 0 };
    vector<string> word_List;
	vector<string>* wordle_Solutions;
    Lists();
    
};
#endif