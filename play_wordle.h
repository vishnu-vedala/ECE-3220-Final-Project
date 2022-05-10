#include "Strategy.h"
#include "singleton.h"
#include <fstream>
#include <string>

class Play_Wordle : public GameMode{
    public:
        Play_Wordle();
        std::string getAnswer();
        
    private:

        std::string answer_;
};

class ChooseWord : public Strategy{
    public:
        std::string retrieve_answer(Play_Wordle* wordle) override;
    
    private:
        Play_Wordle* wordle;
};

class ChooseDay : public Strategy{
    public:
        std::string retrieve_answer(Play_Wordle* wordle) override;

    private:
        Play_Wordle* wordle;
};

