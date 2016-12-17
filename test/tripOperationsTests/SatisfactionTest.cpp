//
// Created by nevo on 04/12/16.
//

#include <gtest/gtest.h>
#include "../../src/tripOperations/Satisfaction.h"

class SatisfactionTest : public ::testing::Test {
protected:
    Satisfaction *sat;

    virtual void SetUp() {
        sat = new Satisfaction();
    }

    virtual void TearDown() {
        delete (sat);
    }
};

/**
 * checks the getAverage method.
 * checks if the average is computed properly.
 */
TEST_F(SatisfactionTest, getAverage) {
    sat->update(4);
    sat->update(5);
    sat->update(2);
    sat->update(3);
    ASSERT_TRUE(sat->getAverage() == 3.5) << "failed at getting the right avarage";
}

/**
 * checks the update method.
 * checks if the satisfaction updated properly.
 */
TEST_F(SatisfactionTest, update) {
    sat->update(3);
    sat->update(-5);
    sat->update(4);
    sat->update(-9);
    sat->update(0);
    ASSERT_TRUE(sat->getAverage() == 3.5) << "failed at updating the right avarage";
}