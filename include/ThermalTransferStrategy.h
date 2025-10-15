// ThermalTransferStrategy.h
#pragma once
#include "LabelStrategy.h"

class ThermalTransferStrategy : public LabelStrategy {
public:
    void printLabel(double weight) override;
};
