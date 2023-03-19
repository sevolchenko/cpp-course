#pragma once
#include "ConsumingEntity.h"
class Pest :
    public ConsumingEntity
{
public:
    Pest(int consumes) : ConsumingEntity(consumes) {}
};

