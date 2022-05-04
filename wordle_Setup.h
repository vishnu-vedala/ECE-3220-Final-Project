#ifndef WORDLE_SETUP_H
#define WORDLE_SETUP_H


#include <vector>
#include <string>


using namespace std;


class wordle_Setup{

    private :
	int letter_Values[5][26];

    public :
<<<<<<< HEAD
=======
    std::string get_answer() override;
>>>>>>> 2f3057a (plz work)
    void import_Words();
	void value_Letters();
	void get_letter_Values(int i, int j);
};

#endif
     
