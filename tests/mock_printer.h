// tests/mock_printer.h
#pragma once
#include "Printer.h"
#include <gmock/gmock.h>
#include "ThermalDirectStrategy.h"

class MockPrinter : public Printer {
public:
    MockPrinter() : Printer(std::make_unique<ThermalDirectStrategy>()) {} // call base class constructor with null
    MOCK_METHOD(void, execute, (), (override));
    MOCK_METHOD(void, setWeight, (double), (override));
};
