#pragma once
#include "ConsumingEntity.h"
class PolicemanAnt :
    public ConsumingEntity
{
public:
    PolicemanAnt(int consumes, double increases) : ConsumingEntity(consumes) {
        this->_increases = increases;
    }
    double getIncreases() {
        return _increases;
    }
    void setIncreases(double increases) {
        this->_increases = increases;
    }
private:
    double _increases = 0;
};

