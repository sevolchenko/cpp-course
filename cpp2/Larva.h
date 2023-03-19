#pragma once
#include "ConsumingEntity.h"
class Larva :
    public ConsumingEntity
{
public:
    Larva(int consumes) : ConsumingEntity(consumes) {}
    bool operator == (const Larva& larva) const { return _consumes == larva._consumes; }
};