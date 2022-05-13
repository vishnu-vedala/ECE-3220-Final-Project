#include "singleton.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Play_Wordle{
    public:
        Play_Wordle();
        void getAnswer();
        void set_guess_program();
        void set_guess_user();
        int set_result();
        void update_list();
        int result[5] = { 0 };
        bool myEquals(string a, string b);
        string get_guess();
        int printsize = 5;

        
    private:
        string answer_ = "brady";
        string guess_;
        int guesses = 0;
        
};
