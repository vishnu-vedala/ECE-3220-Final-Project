#include "play_wordle.h"

Play_Wordle::Play_Wordle(){

}

std::string Play_Wordle::getAnswer(){
    GameMode* game = new GameMode();
    std::string answer;
    std::cout << "Input desired answer as a 5 (lowercase) letter word or a 3 digit day number (Ex: 001 for Day 1 Wordle solution): ";
    std::cin >> answer;
    if(answer.size() == 5){
        for(long unsigned i = 0; i < Singleton::getInstance()->getlists()->word_List.size(); i++){
            std::string temp = Singleton::getInstance()->getlists()->word_List[i];
            if(answer == temp){
                std::cout << "Word accepted...Beginning Wordle..." << std::endl;
                
                break;
            }
            if(i + 1 == Singleton::getInstance()->getlists()->word_List.size()){
                std::cout << "Word not found in the Wordle word list. Please try again." << std::endl;
                return; 
            }
        }
    }
    else if(answer.size() != 5)
        std::cout << "Word is not 5 letters long, please input a new word." << std::endl;
        getAnswer();
    }
}


/* ChooseWord strategy implementation */
std::string ChooseWord::retrieve_answer(){
    std::string answer;
    std::cout << "Input desired answer as a 5 letter word: ";
    std::cin >> answer;
    /*
    for(long unsigned i = 0; i < Singleton::getInstance()->getlists()->word_List.size(); i++){
        std::string temp = Singleton::getInstance()->getlists()->word_List[i];
        if(answer == temp){
            std::cout << "Word accepted...Beginning Wordle..." << std::endl;
            break;
        }
        if(i + 1 == Singleton::getInstance()->getlists()->word_List.size()){
            std::cout << "Word not found in the Wordle word list. Please try again." << std::endl;
            return; 
        }
    }
    */
    answer_ = answer;
}

