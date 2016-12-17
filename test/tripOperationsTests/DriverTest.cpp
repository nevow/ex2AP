//
// Created by nevo on 03/12/16.
//

#include <gtest/gtest.h>
#include "../../src/taxi/Cab.h"
#include "../../src/tripOperations/Driver.h"

class DriverTest : public ::testing::Test {
protected:
    Driver *d;
    Taxi *cab;

    virtual void SetUp() {
        d = new Driver(305, 40, MartialStatues::WIDOWED, 7, 0);
        cab = new Cab(Color::GREEN, CarManufacture::TESLA, 0);
        d->setCab(cab);
    }

    virtual void TearDown() {
        delete (d);
        delete (cab);
    }
};

/**
 * check getId method.
 */
TEST_F(DriverTest, getId) {
    ASSERT_TRUE(d->getId() == 305);
}

/**
 * check getAge method.
 */
TEST_F(DriverTest, getAge) {
    ASSERT_TRUE(d->getAge() == 40);
}


/**
 * check getStatus method.
 */
TEST_F(DriverTest, getStatus) {
    ASSERT_TRUE(d->getStatus() == MartialStatues::WIDOWED);
}

/**
 * check getExperience method.
 */
TEST_F(DriverTest, getExperience) {
    ASSERT_TRUE(d->getExperience() == 7);
}

/**
 * check getVehicle_id method.
 */
TEST_F(DriverTest, getVehicle_id) {
    ASSERT_TRUE(d->getVehicle_id() == 0);
}

/**
 * check getSatisfaction method.
 */
TEST_F(DriverTest, getSatisfaction) {
    Satisfaction sat;
    sat.update(5);
    sat.update(2);
    d->updateSatisfaction(5);
    d->updateSatisfaction(2);
    ASSERT_TRUE(d->getSatisfaction()->getAverage() == sat.getAverage());
}

/**
 * check getAndSetTi method.
 */
TEST_F(DriverTest, getAndSetTi) {
    Point *start = new Point(3, 3);
    Point *destination = new Point(4, 3);
    Point *otherStart = new Point(start->getX(), start->getY());
    Point *otherEnd = new Point(destination->getX(), destination->getY());
    TripInfo *ti = new TripInfo(300, start, destination, 3, 100);
    TripInfo ti2(300, otherStart, otherEnd, 3, 100);
    d->setTi(ti);
    ASSERT_TRUE(*ti == ti2);
    EXPECT_TRUE(*(d->getTi()) == ti2);
}

/**
 * check getAndSetCab method.
 */
TEST_F(DriverTest, getAndSetCab) {
    Cab cab1(Color::GREEN, CarManufacture::TESLA, 0);
    Cab cab2(Color::GREEN, CarManufacture::TESLA, 0);
    ASSERT_TRUE(cab1 == cab2);
    d->setCab(&cab1);
    EXPECT_TRUE(*(d->getCab()) == cab2);
}

/**
 * check setStatus method.
 */
TEST_F(DriverTest, setStatus) {
    d->setStatus(MartialStatues::SINGLE);
    ASSERT_TRUE(d->getStatus() == MartialStatues::SINGLE);
}

/**
 * check setExperience method.
 */
TEST_F(DriverTest, setExperience) {
    d->setExperience(8);
    ASSERT_TRUE(d->getExperience() == 8);
}

/**
 * check moveOneStep method.
 * compares expected location after moveOneStep and the real location.
 */
TEST_F(DriverTest, moveOneStep) {
    Point *start = new Point(3, 3);
    Point *destination = new Point(4, 3);
    d->setTi(new TripInfo(300, start, destination, 3, 100));
    d->moveOneStep();
    ASSERT_TRUE(*(d->getCab()->getLocation()->getP()) == *destination);
}

/**
 * check updateSatisfaction method.
 */
TEST_F(DriverTest, updateSatisfaction) {
    Satisfaction sat;
    sat.update(5);
    sat.update(7);
    d->updateSatisfaction(5);
    d->updateSatisfaction(7);
    ASSERT_TRUE(d->getSatisfaction()->getAverage() == sat.getAverage());
}

/**
 * check equality method.
 * compares 2 identical drivers.
 */
TEST_F(DriverTest, equality) {
    Driver d1(305, 40, MartialStatues::WIDOWED, 7, 0);
    Driver d2(305, 40, MartialStatues::WIDOWED, 7, 0);
    ASSERT_TRUE(d1 == d2);
}

/**
 * check notEquality method.
 * compares 2 not identical drivers.
 */
TEST_F(DriverTest, notEquality) {
    Driver d1(305, 40, MartialStatues::WIDOWED, 7, 0);
    Driver d2(302, 40, MartialStatues::WIDOWED, 7, 0);
    ASSERT_TRUE(d1 != d2);
}
