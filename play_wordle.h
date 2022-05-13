#include "singleton.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Play_Wordle{
    public:
        Play_Wordle();
        void retrieve_answer(); //pulls the user-inputted answer from either the word_List vector of scrabble words if given a 5 letter word or the wordle_Solutions vector if given a day number.
        void set_guess_program(); //finds, guesses, and cout's the best guess if the program is the one playing
        void set_guess_user(); //suggests top 5 guesses then prompts user to input their guess.
        int set_result(); //prints out a 5 digit combination of 0s, 1s, and 2s to show the accuracy of the guess.
        void update_list(); //updates list of suggested guesses based on the result of the previous guesses.
        int result[5] = { 0 };
        bool myEquals(string a, string b); //function to compare two strings. Needed so we can compare strings like answer and guess to an element in our string vectors.
        string get_guess(); //getter function for guess_
        int printsize = 5;

        
    private:
        string answer_;
        string guess_;
        //int guesses = 0;
        
};
