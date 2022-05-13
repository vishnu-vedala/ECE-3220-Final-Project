#include "strategy.h"
#include "singleton.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Play_Wordle{
    public:
        Play_Wordle();
        std::string getAnswer();
        void set_guess_program();
        void set_guess_user();
        int set_result();
        int result[5] = { 0 };
        bool myEquals(string a, string b);

        
    private:
        string answer_ = "angry";
        string guess_;
        int guesses = 0;
        
};

class ChooseWord : public Strategy{
    public:
        //std::string retrieve_answer(Play_Wordle* wordle) override;
    
    private:
        //Play_Wordle* wordle;
};

class ChooseDay : public Strategy{
    public:
        //std::string retrieve_answer(Play_Wordle* wordle) override;

    private:
        //Play_Wordle* wordle;
};

