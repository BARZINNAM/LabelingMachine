#include "Scale.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>


void Scale::execute() 
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    weight = 100 + (std::rand() % 50) / 10.0;
    std::cout << "[Scale] Measured weight: " << weight << "g\n";
}

std::string Scale::name() const {return "Scale";}