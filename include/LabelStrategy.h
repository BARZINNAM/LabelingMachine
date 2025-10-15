
#pragma once
#include <iostream>

class LabelStrategy {
public:
    virtual ~LabelStrategy() = default;
    virtual void printLabel(double weight) = 0;
};
