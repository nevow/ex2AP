//
// Created by nevo on 04/12/16.
//

//
// Created by nevo on 04/12/16.
//

#include <gtest/gtest.h>
#include "../../src/tripOperations/Driver.h"
#include "../../src/taxi/LuxuryCab.h"

class LuxuryCabTest : public ::testing::Test {
protected:
    Point *start;
    Point *destination;
    Node *location;
    Node *endLocation;
    LuxuryCab *cab1;
    LuxuryCab *cab2;
    LuxuryCab *cab3;
    Driver *d;

    virtual void SetUp() {
        start = new Point(3, 3);
        destination = new Point(3, 5);
        location = new Node(start);
        endLocation = new Node(destination);
        cab1 = new LuxuryCab(Color::GREEN, CarManufacture::TESLA, 4453523 );
        cab2 = new LuxuryCab( Color::GREEN, CarManufacture::TESLA, 4453523 );
        cab3 = new LuxuryCab( Color::RED, CarManufacture::HONDA, 4355234);
        d = new Driver(305, 40, MartialStatues::WIDOWED, 7, 0);
    }

    virtual void TearDown() {
        delete (d);
        delete (cab1);
        delete (cab2);
        delete (cab3);
        delete (location);
        delete (endLocation);
    }
};

/**
 * checks the move method.
 * checks if the cab moved correctly.
 */
TEST_F(LuxuryCabTest, move) {
    d->setCab(cab1);
    //cab1->move();
    ASSERT_TRUE(*(cab1->getLocation()) == *endLocation);
}

/**
 * checks the getLocation method.
 * checks if the cab returns the correct location.
 */
TEST_F(LuxuryCabTest, getLocation) {
    ASSERT_TRUE(*(cab1->getLocation()) == *location);
}

/**
 * checks the equality method.
 * checks if two identical cabs are equal.
 */
TEST_F(LuxuryCabTest, equality) {
    ASSERT_TRUE(*cab1 == *cab2);
}

/**
 * checks the notEquality method .
 * checks if two not identical cabs are not equal.
 */
TEST_F(LuxuryCabTest, notEquality) {
    ASSERT_TRUE(*cab1 != *cab3);
    ASSERT_TRUE(*cab2 != *cab3);
}