#include "Printer.h"
#include <iostream>
#include <thread>


Printer::Printer(std::unique_ptr<LabelStrategy> s) : strategy(std::move(s))
{}

void Printer::setStrategy(std::unique_ptr<LabelStrategy> s) 
{
    strategy = std::move(s);
}

void Printer::setWeight(double w) 
{
    lastWeight = w;
}

void Printer::execute()  
{
    if (strategy) {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        strategy->printLabel(lastWeight);
    } else {
        std::cout << "[Printer] No print strategy set!\n";
    }
}

std::string Printer::name() const  { return "Printer"; }