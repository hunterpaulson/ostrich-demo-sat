/*
 * NavPwrTester.cpp
 *
 *  Created on: July 19, 2017
 *      Author: Gorang Gandhi
 */

#include <Tester.hpp>
#include <gtest/gtest.h>
#include <Fw/Test/UnitTest.hpp>

TEST(TestNominal,ServoTest) {
    RobotArm::Tester tester;
    tester.servoTest();
}

TEST(TestNominal,EnableTest) {
    RobotArm::Tester tester;
    tester.enableTest();
}

TEST(TestNominal,DisableTest) {
    RobotArm::Tester tester;
    tester.disableTest();
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


