//
// Created by nevo on 04/12/16.
//

#include <gtest/gtest.h>
#include "../../src/coordinates/Point.h"
#include "../../src/tripOperations/Passenger.h"

class PassengerTest : public ::testing::Test {
protected:
    Point *start;
    Point *destination;
    Passenger *pass;

    virtual void SetUp() {
        start = new Point(2, 2);
        destination = new Point(5, 6);
        pass = new Passenger(start, destination);
    }

    virtual void TearDown() {
        delete (start);
        delete (destination);
        delete (pass);
    }
};

/**
 * checks the generateSatisfaction method.
 * checks if the satisfaction created is in range.
 */
TEST_F(PassengerTest, generateSatisfaction) {
    int satisfaction = pass->generateSatisfaction();
    ASSERT_TRUE(satisfaction >= 1);
    ASSERT_TRUE(satisfaction <= 5);
}