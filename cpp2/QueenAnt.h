#pragma once
#include "ConsumingEntity.h"
#include "Larva.h"

#include <list>
#include <string>

using namespace std;


enum class AntRole { WORKER, POLICEMAN, SOLDIER };

class QueenAnt :
    public ConsumingEntity
{
public:
    QueenAnt(int consumes, int produces) : ConsumingEntity(consumes) {
        this->_produces = produces;
    }

    Larva produceOne(int consumes) {
        return Larva(consumes);
    }
    
    AntRole decide() {
        return AntRole(rand() % 3);
    }

    int getProduces() {
        return _produces;
    }
    void setProduces(int produces) {
        this->_produces = produces;
    }

private:
    int _produces = 0;
};

