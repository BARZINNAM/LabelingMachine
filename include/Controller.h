// Controller.h
#pragma once

#include "Conveyor.h"
#include "Scale.h"
#include "Printer.h"


class Controller {
    Conveyor conveyor;
    Scale scale;
    Printer* printer;

public:
    Controller(Printer* p);

    void runCycle(int cycleNum);

    void switchToThermalTransfer();
    
};
