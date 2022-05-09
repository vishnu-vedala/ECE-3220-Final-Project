#include <iostream>


class Strategy{
    public:
        virtual ~Strategy(){}
        virtual std::string get_answer(std::string answer);
};

class Context{
    private:
        Strategy *strategy_;

    public:
        Context(Strategy* strategy = nullptr) : strategy_(strategy){}
        ~Context(){
            delete this->strategy_;
        }
        void set_strategy(Strategy* strategy){
            delete this->strategy_;
            this->strategy_ = strategy; 
        }
};
