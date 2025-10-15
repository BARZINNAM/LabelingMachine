// ThermalDirectStrategy.h
#pragma once
#include "LabelStrategy.h"

class ThermalDirectStrategy : public LabelStrategy {
public:
    void printLabel(double weight) override;
};