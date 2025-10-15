
#pragma once
#include "MachineComponent.h"


class Conveyor : public MachineComponent {
public:
    void execute() override;
    std::string name() const override ;
};
