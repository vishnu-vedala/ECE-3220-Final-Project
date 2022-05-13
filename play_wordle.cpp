#include "play_wordle.h"
#include <string.h>

using namespace std;

Play_Wordle::Play_Wordle(){}

void Play_Wordle::retrieve_answer(){
    std::string answer;
    std::cout << "Input desired answer as a 5 (lowercase) letter word or a day number (0 - 2314): ";
    std::cin >> answer;
    std::cout << answer << std::endl;
    if(answer.size() == 5){
        for(long unsigned i = 0; i < Singleton::getInstance()->getlists()->word_List.size(); i++){
            std::string temp = Singleton::getInstance()->getlists()->word_List[i];
            if(myEquals(answer, temp)){
                std::cout << "Word accepted...Beginning Wordle..." << std::endl;
                answer_ = answer;
                return;
            }
            if(i + 1 == Singleton::getInstance()->getlists()->word_List.size()){
                std::cout << "Word not found in the Wordle word list. Please try again." << std::endl;
                return; 
            }
        }
    }
    else if(answer.size() != 5){
        std::cout << "Word is not 5 letters long, please input a new word." << std::endl;
        retrieve_answer();
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
            //cout << "found" << endl;
            Singleton::getInstance()->getlists()->word_List.erase(Singleton::getInstance()->getlists()->word_List.begin() + i);
            Singleton::getInstance()->getlists()->letter_Values_vec.erase(Singleton::getInstance()->getlists()->letter_Values_vec.begin() + i);
        }
    }
}

string Play_Wordle::get_guess(){
    return this->guess_;
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
    cout << "please enter a 5 letter word" << endl;
    cin >> tempguess;
    if(tempguess.size() != 5){
        cout << "please enter a 5 letter scrabble word" << endl;
        this->set_guess_user();
    }
    guess_ = tempguess;
    cout << "guess: " << guess_ << endl;
    //Singleton::getInstance()->getlists()->word_List = vector<string>({"hello", "break", "tests"});
    //cout << Singleton::getInstance()->getlists()->word_List[2145] << endl;
    //cout << strcmp(Singleton::getInstance()->getlists()->word_List[2145], "break") << endl;
    
    for(long unsigned i = 0; i < Singleton::getInstance()->getlists()->word_List.size(); i++){
        if(this->myEquals(guess_, Singleton::getInstance()->getlists()->word_List[i])){
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

void Play_Wordle::update_list(){

    string tempw;
    bool ignore = true;
    int count = 0;
    
     for(long unsigned i = 0; i < Singleton::getInstance()->getlists()->word_List.size(); i++){
        //int i = 9752;
        //cout << Singleton::getInstance()->getlists()->word_List[i] << end;
        tempw = Singleton::getInstance()->getlists()->word_List[i];
        ignore = true;
        for(int j = 0; j < 5; j++){ 
            if(ignore){
                switch(result[j]){
                    case 0:
                        for(int k = 0; k < 5; k++){
                            if(guess_[j] == tempw[k]){
                                if(ignore){
                                    Singleton::getInstance()->getlists()->word_List.erase(Singleton::getInstance()->getlists()->word_List.begin() + i);
                                    Singleton::getInstance()->getlists()->letter_Values_vec.erase(Singleton::getInstance()->getlists()->letter_Values_vec.begin() + i);
                                    //cout << Singleton::getInstance()->getlists()->word_List[i-1];
                                    ignore = false;
                                    i--;
                            }
                        }
                    }
                    break;
                    
                    case 1:
                        if(ignore){
                        for(int k = 0; k < 5; k++){
                            if(guess_[j] == tempw[k]){
                                count++;
                            }
                        }
                        
                            if(count == 0){
                                Singleton::getInstance()->getlists()->word_List.erase(Singleton::getInstance()->getlists()->word_List.begin() + i);
                                Singleton::getInstance()->getlists()->letter_Values_vec.erase(Singleton::getInstance()->getlists()->letter_Values_vec.begin() + i);
                                ignore = false;
                                count = 0;
                                i--;
                            }
                        }

                        if(ignore){
                            if(guess_[j] == tempw[j]){
                                Singleton::getInstance()->getlists()->word_List.erase(Singleton::getInstance()->getlists()->word_List.begin() + i);
                                Singleton::getInstance()->getlists()->letter_Values_vec.erase(Singleton::getInstance()->getlists()->letter_Values_vec.begin() + i);
                                ignore = false;
                                i--;
                            }
                        }
                    break;

                    case 2:
                        if(guess_[j] != tempw[j]){
                            Singleton::getInstance()->getlists()->word_List.erase(Singleton::getInstance()->getlists()->word_List.begin() + i);
                            Singleton::getInstance()->getlists()->letter_Values_vec.erase(Singleton::getInstance()->getlists()->letter_Values_vec.begin() + i);
                            ignore = false;
                            i--;
                        }
                        
                        
                    
                        

                    }
                }
            }
        }

    }
    
        //cout << Singleton::getInstance()->getlists()->word_List[12] << " " << Singleton::getInstance()->getlists()->word_List.size() << endl;
        
     
     
     //}
     //cout << Singleton::getInstance()->getlists()->word_List.size();




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