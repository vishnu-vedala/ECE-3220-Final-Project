#ifndef STRATEGY_H
#define STRATEGY_H


#include <iostream>


class Strategy{
    public:
        virtual ~Strategy(){}
        virtual std::string retrieve_answer() = 0;
};

class GameMode{
    private:
        Strategy *strategy_;

    public:
        GameMode(Strategy* strategy);
        ~GameMode();
        void set_strategy(Strategy* strategy);
        void store_answer();
};

#endif