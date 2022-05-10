#include "Strategy.h"
#include "singleton.h"
#include <fstream>
#include <string>

class ChooseWord : public Strategy{
    std::string get_answer() override;
};

class ChooseDay : public Strategy{
    public:
    std::string get_answer() override;
};
