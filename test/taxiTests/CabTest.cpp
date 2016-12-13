//
// Created by nevo on 04/12/16.
//

#include <gtest/gtest.h>
#include "../../src/tripOperations/Driver.h"
#include "../../src/taxi/Cab.h"

class CabTest : public ::testing::Test {
protected:
    Point *start;
    Point *destination;
    Node *location;
    Node *endLocation;
    Cab *cab1;
    Cab *cab2;
    Cab *cab3;
    Driver *d;

    virtual void SetUp() {
        start = new Point(3, 3);
        destination = new Point(3, 4);
        location = new Node(start);
        endLocation = new Node(destination);
        cab1 = new Cab(Color::GREEN, CarManufacture::TESLA, 4453523);
        cab2 = new Cab(Color::GREEN, CarManufacture::TESLA, 4453523);
        cab3 = new Cab( Color::RED, CarManufacture::HONDA,  4355234);
        d = new Driver(40,50, MartialStatues::WIDOWED, 7, 0);
        d->setCab(cab1);
    }

    virtual void TearDown() {
        delete (location);
        delete (endLocation);
        delete (cab1);
        delete (cab2);
        delete (cab3);
        delete (d);
    }
};

/**
 * checks the move method.
 * checks if the cab moved correctly.
 */
TEST_F(CabTest, move) {
    //cab1->move();
    ASSERT_TRUE(*(cab1->getLocation()) == *endLocation);
}

/**
 * checks the getLocation method.
 * checks if the cab returns the correct location.
 */
TEST_F(CabTest, getLocation) {
    ASSERT_TRUE(*(cab1->getLocation()) == *location);
}

/**
 * checks the equality method.
 * checks if two identical cabs are equal.
 */
TEST_F(CabTest, equality) {
    ASSERT_TRUE(*cab1 == *cab2);
}

/**
 * checks the notEquality method .
 * checks if two not identical cabs are not equal.
 */
TEST_F(CabTest, notEquality) {
    ASSERT_TRUE(*cab1 != *cab3);
    ASSERT_TRUE(*cab2 != *cab3);
}