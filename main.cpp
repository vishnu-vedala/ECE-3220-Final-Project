#include "singleton.h"
#include "wordle_Setup.h"
#include <string.h>
#include "play_wordle.h"
#include <stdlib.h>
#include <stdio.h>  

int main(int argc, char** argv) {
    bool win = false;
    int counter = 0;

    if(argc != 2){
        cout << "Please use one flag. Use flag -h for help" << endl;   
        return 1;
    }

    if(!strcmp(argv[1], "-h")){
        cout << "help output" << endl;
        cout << "Use ./make to run the Wordle program. Use the flags to choose who is playing Wordle." << endl << endl;
        cout << "FLAGS:" << endl << "add flag(s) after ./make Ex: ./make (flag)" << endl;
        cout << "program: Use the \"program\" flag if you want our program to play Wordle. It will prompt you to input five letter word, and our program will try to solve Wordle with the inputted word as the answer. Ex: ./make program" << endl;
        cout << "user: Use the \"user\" flag if you want to play Wordle. It will prompt you to input a five letter word. Our program will suggest guesses to the user.  Ex: ./make user" << endl;
        cout << "-h: Help page that outlines the programs usage. Ex: ./make -h" << endl;
        return 0;
    }

    int mode = 0;
    if(!strcmp(argv[1]," Program") || !strcmp(argv[1],"program")){
        mode = 1;
    }
    else if(!strcmp(argv[1],"user") || !strcmp(argv[1], "User")){
        mode = 2;
    }
    else {
        cout << "please use flags 'program' or 'user'. Use -h for help" << endl;
        return 1;
    }

    wordle_Setup* Setup = new wordle_Setup();
    Play_Wordle* Play = new Play_Wordle();
    Setup->import_Words();
    Setup->value_Letters();
    Setup->order_Words();
    Play->retrieve_answer();
    while(!win){

        if(Singleton::getInstance()->getlists()->word_List.size() < 5){
            Play->printsize = Singleton::getInstance()->getlists()->word_List.size();
        }

        counter++;
        if( mode == 1){
            Play->set_guess_program();
        }
        if( mode == 2){
            Play->set_guess_user();
        }
     Play->set_result();
    cout << "result: ";
    for(int i = 0; i < 5; i++){
        switch(Play->result[i]){
            case 0:
                cout <<  "\033[7;37m" << Play->result[i] << "\033[0m";
                break;
            case 1:
                cout <<  "\033[7;33m" << Play->result[i] << "\033[0m";
                break;                
            case 2:
                cout <<  "\033[7;32m" << Play->result[i] << "\033[0m";
                break; 
        } 
    }
    
    Play->update_list();

    

    if(Play->set_result() == 5){
        win = true;
    }

    if(!win)
        cout << endl << "Available Words: " << Singleton::getInstance()->getlists()->word_List.size() << endl;
    
    cout << endl;

    }

    if(win)
    cout << "you win! " << counter << endl;


    for(long unsigned i = 0; i < Singleton::getInstance()->getlists()->word_List.size(); i++){
        cout << Singleton::getInstance()->getlists()->word_List[i];
    }
    
    delete Play;
    delete Setup;
    delete Singleton::getInstance()->getlists();
    delete Singleton::getInstance();

    return 0;
}