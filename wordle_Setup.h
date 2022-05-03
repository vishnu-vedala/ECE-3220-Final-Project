#ifndef WORDLE_SETUP_H
#define WORDLE_SETUP_H


#include <vector>
#include <string>


using namespace std;


class wordle_Setup{

    private :
	int letter_Values[][];

    public :
        void import_Words();
	void value_Letters();
	void get_letter_Values(int i, int j);
};

#endif
     
