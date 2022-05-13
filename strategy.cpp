#include "Strategy.h"

GameMode::GameMode(Strategy* strategy){
    strategy_ = strategy;
}

GameMode::~GameMode(){
    delete strategy_;
}

void GameMode::set_strategy(Strategy* strategy){
    delete strategy_;
    strategy_ = strategy;
}

void GameMode::store_answer(){
    //strategy_->get_answer();
}