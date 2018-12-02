#pragma once

#include "condition/and_condition.h"

class OneCondition : public Condition<int>
{
public:
    bool match(const int& item) const override
    {
        return item == 1;
    }
};

class TwoCondition : public Condition<int>
{
public:
    bool match(const int& item) const override
    {
        return item == 2;
    }
};