//
// TripInfoTest.
//

#include <gtest/gtest.h>
#include "../../src/tripOperations/TripInfo.h"

class TripInfoTest : public ::testing::Test {
protected:
    Point *start;
    Point *destination;
    TripInfo *ti;

    virtual void SetUp() {
        start = new Point(3, 3);
        destination = new Point(4, 3);
        ti = new TripInfo(100, start, destination, 1, 100);
    }

    virtual void TearDown() {
        delete (ti);
    }
};

/**
 * checks the getTariff method.
 */
TEST_F(TripInfoTest, getTariff) {
    ASSERT_TRUE(ti->getTariff() == 100) << "can't get the right tariff";
}

/**
 * checks the checkEnd method.
 * checks if the trip info knows to tell when the trip ended depends on current location.
 */
TEST_F(TripInfoTest, checkEnd) {
    ASSERT_FALSE(ti->checkEnd(start)) << "can't calculate the end point right";
    ASSERT_TRUE(ti->checkEnd(destination)) << "can't calculate the end point right";
}

/**
 * checks the getRoad method.
 * checks if the trip info knows its road.
 */
TEST_F(TripInfoTest, getRoad) {
    CoordinatedItem *item = ti->getRoad()->top();
    ti->getRoad()->pop();
    int **coords = item->getCoordinates();
    Point p(*(coords[0]), *(coords[1]));
    p.deleteCoords(coords);
    delete (item);
    ASSERT_TRUE(p == *destination) << "can't get the right end point";
}

/**
 * checks the getAmountOfPassengers method.
 * checks if the trip info knows its amount of passengers.
 */
TEST_F(TripInfoTest, getAmountOfPassengers) {
    ASSERT_TRUE(ti->getAmountOfPassengers() == 1) << "can't get the right amount of passengers";
}

/**
 * checks the getPassengers method.
 * checks if the trip info knows its passengers.
 */
TEST_F(TripInfoTest, getPassengers) {
    int i = 0;
    std::list<Passenger *> *passengers = ti->getPassengers();
    while (!passengers->empty()) {
        i++;
        delete (passengers->front());
        passengers->pop_front();
    }
    ASSERT_TRUE(ti->getAmountOfPassengers() == i) << "amount of passengers not synced with list";
}

/**
 * checks the getPassengers method.
 * checks if the trip info knows its start.
 */
TEST_F(TripInfoTest, getStart) {
    ASSERT_TRUE(*(ti->getStart()) == *start) << "amount of passengers not synced with list";
}

/**
 * checks the equality method.
 * compares 2 identical trip info.
 */
TEST_F(TripInfoTest, equality) {
    Point *otherStart = new Point(start->getX(), start->getY());
    Point *otherEnd = new Point(destination->getX(), destination->getY());
    TripInfo ti1(100, otherStart, otherEnd, 1, 100);
    EXPECT_TRUE(ti1 == *ti) << "same trip info. should be equal";
}

/**
 * checks the notEquality method.
 * compares 2 not identical trip info.
 */
TEST_F(TripInfoTest, notEquality) {
    Point *otherStart = new Point(6, 6);
    Point *otherEnd = new Point(5, 5);
    TripInfo ti1(54, otherStart, otherEnd, 2, 54);
    EXPECT_TRUE(ti1 != *ti) << "not the same trip info. should be not equal";
}
