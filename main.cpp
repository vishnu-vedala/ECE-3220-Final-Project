#include "singleton.h"
#include "strategy.h"
#include "wordle_Setup.h"

void main() {
    wordle_Setup wordle_Setup = new wordle_Setup;
    wordle_Setup.import_Words;
    wordle_Setup.value_Letters;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 5; j++){
            cout << i << " " << j << " " << wordle_Setup.get_letter_Values(i, j) << endl;
        }
    }
}