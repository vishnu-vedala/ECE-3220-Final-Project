#include "play_wordle.h"

std::string ChooseWord::get_answer(){
    std::string answer;
    std::cout << "Input answer as a word: ";
    std::cin >> answer;
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