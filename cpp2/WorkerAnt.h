#pragma once
#include "ConsumingEntity.h"
class WorkerAnt :
    public ConsumingEntity
{
public:
    WorkerAnt(int consumes, int collects) : ConsumingEntity(consumes) {
        this->_collects = collects;
    }
    int getCollects() {
        return _collects;
    }
    void setCollects(int collects) {
        this->_collects = collects;
    }
private:
    int _collects =0;
};

