#include "Controller.h"
#include <iostream>
#include <thread>
#include "ThermalDirectStrategy.h"
#include "ThermalTransferStrategy.h"


Controller::Controller(Printer* p):
    //printer(std::make_unique<ThermalDirectStrategy>())
    printer(p)
{}


void Controller::runCycle(int cycleNum) 
{
    std::cout << "\n=== Cycle " << cycleNum << " ===\n";

    std::thread t1([this] { conveyor.execute(); });
    std::thread t2([this] { scale.execute(); });

    // Wait for both threads
    t1.join();
    t2.join();

    // Get weight result and pass to printer
    printer->setWeight(scale.weight);
    printer->execute();

    std::cout << "=== End of Cycle " << cycleNum << " ===\n";
}

void Controller::switchToThermalTransfer() 
{
    printer->setStrategy(std::make_unique<ThermalTransferStrategy>());
}