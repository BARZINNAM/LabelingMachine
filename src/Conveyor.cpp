#include "Conveyor.h"
#include <iostream>
#include <thread>
#include <chrono>

void Conveyor::execute()
{
    std::cout << "[Conveyor] Moving item on conveyor...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
}

std::string Conveyor::name() const { return "Conveyor"; }