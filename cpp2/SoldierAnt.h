#pragma once
#include "ConsumingEntity.h"
class SoldierAnt :
    public ConsumingEntity
{
public:
    SoldierAnt(int consumes, int eliminates) : ConsumingEntity(consumes) {
        this->_eliminates = eliminates;
    }
    int getElimitanes() {
        return _eliminates;
    }
    void setEliminates(int eliminates) {
        this->_eliminates = eliminates;
    }
private:
    int _eliminates = 0;
};

