// main.cpp
#include "Controller.h"
#include "Printer.h"
#include <memory>
#include <cstdlib>
#include <ctime>
#include "ThermalDirectStrategy.h"
int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Printer printer(std::make_unique<ThermalDirectStrategy>());
    Controller controller(&printer);

    // Run two cycles with Thermal Direct
    controller.runCycle(1);
    controller.runCycle(2);

    // Switch strategy at runtime
    controller.switchToThermalTransfer();
    controller.runCycle(3);

    return 0;
}
