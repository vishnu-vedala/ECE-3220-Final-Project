#include "play_wordle.h"
#include <string.h>

using namespace std;

Play_Wordle::Play_Wordle(){}

std::string Play_Wordle::getAnswer(){
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



/* ChooseWord strategy implementation 
std::string ChooseWord::retrieve_answer(){
    std::string answer;
    std::cout << "Input desired answer as a 5 letter word: ";
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
    */
    //answer_ = answer;
//}

void Play_Wordle::set_guess_program(){
    int maxElementIndex = std::max_element(Singleton::getInstance()->getlists()->letter_Values_vec.begin(), Singleton::getInstance()->getlists()->letter_Values_vec.end()) - Singleton::getInstance()->getlists()->letter_Values_vec.begin();
    guess_ = Singleton::getInstance()->getlists()->word_List[maxElementIndex];
    for(long unsigned i = 0; i < Singleton::getInstance()->getlists()->word_List.size(); i++){
        if(this->myEquals(guess_, Singleton::getInstance()->getlists()->word_List[i])){
            cout << "found" << endl;
            Singleton::getInstance()->getlists()->word_List.erase(Singleton::getInstance()->getlists()->word_List.begin() + i);
            Singleton::getInstance()->getlists()->letter_Values_vec.erase(Singleton::getInstance()->getlists()->letter_Values_vec.begin() + i);
        }
    }
}

void Play_Wordle::set_guess_user(){
    vector<int> tempv = Singleton::getInstance()->getlists()->letter_Values_vec;
    vector<string> tempw = Singleton::getInstance()->getlists()->word_List;
    int maxElementIndex;
    cout << "Suggested guesses: " << endl;
    for(int i = 0; i < 5; i++){
        maxElementIndex = std::max_element(tempv.begin(), tempv.end()) - tempv.begin();
        cout << "   " << tempw[maxElementIndex] << endl;
        tempv.erase(tempv.begin() + maxElementIndex);
        tempw.erase(tempw.begin() + maxElementIndex);
    }
    string tempguess;
    cout << "please enter a 5 letter word or a day number from 0-2314 starting from june 19 2021" << endl;
    cin >> tempguess;
    if(tempguess.size() != 5){
        cout << "please enter a 5 letter scrabble word" << endl;
        this->set_guess_user();
    }
    guess_ = tempguess;
    cout << "guess: " << guess_ << endl;
    //Singleton::getInstance()->getlists()->word_List = vector<string>({"hello", "break", "tests"});
    cout << Singleton::getInstance()->getlists()->word_List[2145] << endl;
    //cout << strcmp(Singleton::getInstance()->getlists()->word_List[2145], "break") << endl;
    
    for(long unsigned i = 0; i < Singleton::getInstance()->getlists()->word_List.size(); i++){
        if(this->myEquals(guess_, Singleton::getInstance()->getlists()->word_List[i])){
            cout << "found" << endl;
            Singleton::getInstance()->getlists()->word_List.erase(Singleton::getInstance()->getlists()->word_List.begin() + i);
            Singleton::getInstance()->getlists()->letter_Values_vec.erase(Singleton::getInstance()->getlists()->letter_Values_vec.begin() + i);
        }
    }
}

bool Play_Wordle::myEquals(string a, string b) {
  return a[0] == b[0] &&
          a[1] == b[1] &&
          a[2] == b[2] &&
          a[3] == b[3] &&
          a[4] == b[4];
}

int Play_Wordle::set_result(){
    for(int i = 0; i < 5; i++){
        result[i] = 0;
    }

    for(int i = 0; i < 5; i++){
        for(int k = 0; k < 5; k++){ 
            if(guess_[i] == answer_[k]){
                result[i] = 1;
            }
        }
        if (answer_[i] == guess_[i]){
            result[i] = 2; 
        }
        else if(result[i] != 1){
            result[i] = 0;
        }
    }
    int count = 0;
    for(int i = 0; i<5; i++){
        if(result[i] == 2){
            count++;
        }
    }
    return count;
}