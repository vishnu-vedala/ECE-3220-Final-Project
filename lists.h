#ifndef LISTS_H
#define LISTS_H


#include <vector>
#include <string>
#include <algorithm>


using namespace std;


class Lists{

public :
    int letter_Values[5][26] = {{0}};
    vector<std::string> word_List;
	vector<std::string> wordle_Solutions;
    vector<int> letter_Values_vec;
    Lists();
    
};
#endif