#include "Strategy.h"
#include <fstream>
#include <string>

class ChooseWord : public Strategy{
    std::string get_answer() override;
    
};