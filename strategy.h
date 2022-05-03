#include <iostream>


class Strategy{
    public:
        virtual ~Strategy(){}
        virtual void GameMode(std::string input) const = 0;
        
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
}