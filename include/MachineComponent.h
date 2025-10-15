#pragma once
#include <string>

class MachineComponent {

public:
    virtual ~MachineComponent() = default;
    virtual void execute() = 0;
    virtual std::string name() const = 0;


};