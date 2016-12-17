//
// LuxuryCabTest.
//

#include <gtest/gtest.h>
#include "../../src/tripOperations/Driver.h"
#include "../../src/taxi/LuxuryCab.h"

/*
 * setup
 */
class LuxuryCabTest : public ::testing::Test {


protected:
    Point *startP;
    Point *midP;
    Point *destP;
    Node *location;
    Node *middleLoc;
    Node *endLocation;
    LuxuryCab *cab1;
    LuxuryCab *cab2;
    LuxuryCab *cab3;
    Driver *driver;
    stack<CoordinatedItem *> *road;

    virtual void SetUp() {
        startP = new Point(3, 3);
        midP = new Point(3, 4);
        destP = new Point(3, 5);
        location = new Node(startP);
        middleLoc = new Node(midP);
        endLocation = new Node(destP);
        cab1 = new LuxuryCab(Color::GREEN, CarManufacture::FIAT, 4453523);
        cab2 = new LuxuryCab(Color::GREEN, CarManufacture::FIAT, 4453523);
        cab3 = new LuxuryCab(Color::RED, CarManufacture::HONDA, 4355234);
        driver = new Driver(40, 50, MartialStatues::WIDOWED, 7, 0);
        driver->setCab(cab1);
        road->push(&*location);
        road->push(&*endLocation);
        road->push(&*middleLoc);
    }

    virtual void TearDown() {
        delete (startP);
        delete (midP);
        delete (destP);
        delete (location);
        delete (endLocation);
        delete (cab1);
        delete (cab2);
        delete (cab3);
        delete (driver);
        while (!road->empty()) {
            delete (road->top());
            road->pop();
        }
        delete road;
    }
};

/**
 * method inherited from Taxi.
 * checks the getId method.
 * checks if the LuxuryCab returns the correct Id.
 */
TEST_F(LuxuryCabTest, getId) {
    ASSERT_TRUE((cab3->getId()) == 4355234);
}

/**
 * method inherited from Taxi.
 * checks the getLocation method.
 * checks if the LuxuryCab returns the correct location.
 */
TEST_F(LuxuryCabTest, getLocation) {
    ASSERT_TRUE(*(cab1->getLocation()) == *location);
}

/**
 * checks the move method.
 * checks if the LuxuryCab moved correctly, and if the road change correctly.
 */
TEST_F(LuxuryCabTest, move) {
    cab1->move(road);
    ASSERT_TRUE(*(cab1->getLocation()) == *middleLoc);
    ASSERT_EQ(*(road->top()), *endLocation);
}

/**
 * method inherited from Taxi.
 * checks the applyToPoint method.
 * checks if the LuxuryCab apply correctly to the point.
 */
TEST_F(LuxuryCabTest, applyToPoint) {
    cab1->applyToPoint(midP);
    ASSERT_EQ(*(cab1->getLocation()), *middleLoc);
}

/**
 * method inherited from Taxi.
 * checks the equality method.
 * checks if two identical cabs are equal.
 */
TEST_F(LuxuryCabTest, equality) {
    ASSERT_TRUE(*cab1 == *cab2);
}

/**
 * method inherited from Taxi.
 * checks the notEquality method.
 * checks if two not identical cabs are not equal.
 */
TEST_F(LuxuryCabTest, notEquality) {
    ASSERT_TRUE(*cab1 != *cab3);
    ASSERT_TRUE(*cab2 != *cab3);
}