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
    sat->update(10);
    sat->update(9);
    ASSERT_TRUE(sat->getAverage() == 7) << "failed at getting the right avarage";
}

/**
 * checks the update method.
 * checks if the satisfaction updated properly.
 */
TEST_F(SatisfactionTest, update) {
    sat->update(4);
    sat->update(5);
    sat->update(10);
    sat->update(9);
    ASSERT_TRUE(sat->getAverage() == 7) << "failed at updating the right avarage";
}