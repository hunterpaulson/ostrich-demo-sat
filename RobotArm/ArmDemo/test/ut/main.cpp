/*
 * NavPwrTester.cpp
 *
 *  Created on: July 19, 2017
 *      Author: Gorang Gandhi
 */

#include <Tester.hpp>
#include <gtest/gtest.h>
#include <Fw/Test/UnitTest.hpp>


TEST(TestNominal,Nominal) {

    RobotArm::Tester tester;

}


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}


