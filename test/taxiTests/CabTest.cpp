//
// CabTest.


#include <gtest/gtest.h>
#include "../../src/tripOperations/Driver.h"
#include "../../src/taxi/Cab.h"

/**
 * setup
 */
class CabTest : public ::testing::Test {

protected:
    Point *startP;
    Point *midP;
    Point *destP;
    Node *location;
    Node *middleLoc;
    Node *endLocation;
    Cab *cab1;
    Cab *cab2;
    Cab *cab3;
    Driver *driver;
    stack<CoordinatedItem *> *road;

    virtual void SetUp() {
        startP = new Point(3, 3);
        midP = new Point(3, 4);
        destP = new Point(3, 5);
        location = new Node(startP);
        middleLoc = new Node(midP);
        endLocation = new Node(destP);
        cab1 = new Cab(Color::GREEN, CarManufacture::FIAT, 4453523);
        cab2 = new Cab(Color::GREEN, CarManufacture::FIAT, 4453523);
        cab3 = new Cab(Color::RED, CarManufacture::HONDA, 4355234);
        driver = new Driver(40, 50, MartialStatues::WIDOWED, 7, 0);
        driver->setCab(cab1);
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
 * checks if the cab returns the correct Id.
 */
TEST_F(CabTest, getId) {
    ASSERT_TRUE((cab3->getId()) == 4355234);
}

/**
 * method inherited from Taxi.
 * checks the getLocation method.
 * checks if the cab returns the correct location.
 */
TEST_F(CabTest, getLocation) {
    ASSERT_TRUE(*(cab1->getLocation()) == *location);
}

/**
 * checks the move method.
 * checks if the cab moved correctly, and if the road change correctly
 */
TEST_F(CabTest, move) {
    cab1->move(road);
    ASSERT_TRUE(*(cab1->getLocation()) == *middleLoc);
    ASSERT_EQ(*(road->top()), *endLocation);
}

/**
 * checks the applyToPoint method.
 * checks if the cab apply correctly to the point.
 */
TEST_F(CabTest, applyToPoint) {
    cab1->applyToPoint(midP);
    ASSERT_EQ(*(cab1->getLocation()), *middleLoc);
}

/**
 * method inherited from Taxi.
 * checks the equality method.
 * checks if two identical cabs are equal.
 */
TEST_F(CabTest, equality) {
    ASSERT_TRUE(*cab1 == *cab2);
}

/**
 * method inherited from Taxi.
 * checks the notEquality method.
 * checks if two not identical cabs are not equal.
 */
TEST_F(CabTest, notEquality) {
    ASSERT_TRUE(*cab1 != *cab3);
    ASSERT_TRUE(*cab2 != *cab3);
}