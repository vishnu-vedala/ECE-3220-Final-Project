#include "singleton.h"
#include "strategy.h"
#include "wordle_Setup.h"

int main() {
    wordle_Setup* Setup = new wordle_Setup();
    Setup->import_Words();
    Setup->value_Letters();
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 5; j++){
            cout << Singleton::getInstance()->getlists()->letter_Values[j][i] << " ";
        }
    cout << endl;
    }
    return 0;
}