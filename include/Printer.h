// Printer.h
#pragma once
#include "LabelStrategy.h"
#include "MachineComponent.h"
#include <memory>


class Printer : public MachineComponent {
    std::unique_ptr<LabelStrategy> strategy;
    double lastWeight{0.0};

public:
    Printer(std::unique_ptr<LabelStrategy> s);

    void setStrategy(std::unique_ptr<LabelStrategy> s);

    virtual void setWeight(double w);

    void execute() override ;

    std::string name() const override ;
};
