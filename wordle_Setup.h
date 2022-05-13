#ifndef WORDLE_SETUP_H
#define WORDLE_SETUP_H


#include <vector>
#include <string>
#include <algorithm>


using namespace std;


class wordle_Setup{

    private :
	

    public :
    void import_Words(); //Fills word_List and wordle_Solutions vectors with the words from "Scrabble list.txt" and "Wordle list.txt"
	void value_Letters(); //Gives letters values based on frequency in words
    void order_Words(); //Orders words from highest total value to lowest
	
};

#endif
     
