
#pragma once
#include "MachineComponent.h"


class Scale : public MachineComponent {
public:
    double weight{0.0};

    void execute() override;

    std::string name() const override;
};
