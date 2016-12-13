//
// Created by nevo on 04/12/16.
//

#include <gtest/gtest.h>
#include "../../src/tripOperations/TripInfo.h"

class TripInfoTest : public ::testing::Test {
protected:
    Point *start;
    Point *destination;
    Passenger *pass;
    list<Passenger *> *passengers;
    TripInfo *ti;

    virtual void SetUp() {
        start = new Point(3, 3);
        destination = new Point(4, 3);
        pass = new Passenger(start, destination);
        passengers = new list<Passenger *>;
        passengers->push_front(pass);
        ti = new TripInfo(100, start, destination, 1, passengers, 100);
    }

    virtual void TearDown() {
        delete (start);
        delete (destination);
        delete (pass);
        delete (ti);
    }
};

/**
 * checks the checkEnd method.
 * checks if the trip info knows to tell when the trip ended depends on current location.
 */
TEST_F(TripInfoTest, checkEnd) {
    ASSERT_TRUE(ti->checkEnd(start)) << "can't calculate the end point right";
    ASSERT_FALSE(ti->checkEnd(destination)) << "can't calculate the end point right";
}

/**
 * checks the equality method.
 * compares 2 identical trip info.
 */
TEST_F(TripInfoTest, equality) {
    TripInfo *ti1 = new TripInfo(100, start, destination, 1, passengers, 100);
    EXPECT_TRUE(*ti1 == *ti) << "same trip info. should be equal";
    delete (ti1);
}

/**
 * checks the notEquality method.
 * compares 2 not identical trip info.
 */
TEST_F(TripInfoTest, notEquality) {
    TripInfo *ti1 = new TripInfo(54, start, destination, 1, passengers, 100);
    EXPECT_TRUE(*ti1 != *ti) << "not the same trip info. should be not equal";
    delete (ti1);
}
