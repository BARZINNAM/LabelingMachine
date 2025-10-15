// tests/test_labeling_machine.cpp

#include <gtest/gtest.h>
#include "../include/Scale.h"
#include "../include/Printer.h"
#include "../include/ThermalDirectStrategy.h"
#include "../include/ThermalTransferStrategy.h"
#include "../include/Controller.h"
#include <gmock/gmock.h>
#include "mock_printer.h"

using namespace std;

TEST(ScaleTest, WeightIsPositive) {
    Scale s;
    s.execute();
    EXPECT_GT(s.weight, 0.0);
}

TEST(ScaleTest, WeightWithinReasonableRange) {
    Scale s;
    s.execute();
    EXPECT_LT(s.weight, 200.0);
}

TEST(PrinterTest, PrintsCorrectText_ThermalDirect) {
    Printer p(make_unique<ThermalDirectStrategy>());
    p.setWeight(123.4);

    testing::internal::CaptureStdout();
    p.execute();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("ThermalDirect"), string::npos);
    EXPECT_NE(output.find("123.4"), string::npos);
}

TEST(PrinterTest, PrintsCorrectText_ThermalTransfer) {
    Printer p(make_unique<ThermalTransferStrategy>());
    p.setWeight(99.9);

    testing::internal::CaptureStdout();
    p.execute();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("ThermalTransfer"), string::npos);
    EXPECT_NE(output.find("99.9"), string::npos);
}

TEST(ControllerTest, CanSwitchStrategyAtRuntime) {
    Printer p(std::make_unique<ThermalDirectStrategy>());
    Controller c(&p);

    // Capture Thermal Direct output
    testing::internal::CaptureStdout();
    c.runCycle(1);
    string directOut = testing::internal::GetCapturedStdout();
    EXPECT_NE(directOut.find("ThermalDirect"), string::npos);

    // Switch to Thermal Transfer
    c.switchToThermalTransfer();

    testing::internal::CaptureStdout();
    c.runCycle(2);
    string transferOut = testing::internal::GetCapturedStdout();
    EXPECT_NE(transferOut.find("ThermalTransfer"), string::npos);
}


// tests/test_labeling_machine.cpp

using ::testing::_;
using ::testing::Exactly;

// Example test using the mock
TEST(ControllerTest, ShouldCallPrinterExecuteOnce) {
    MockPrinter mockPrinter;
    Controller controller(&mockPrinter);

    EXPECT_CALL(mockPrinter, execute())
        .Times(Exactly(2));

    // Simulate how the controller might use the printer
    mockPrinter.setWeight(150.0);
    mockPrinter.execute();

    controller.runCycle(1);
}

