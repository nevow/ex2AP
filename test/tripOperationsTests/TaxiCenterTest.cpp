//
// Created by nevo on 04/12/16.
//
#include <list>
#include <gtest/gtest.h>
#include "../../src/taxi/Cab.h"
#include "../../src/tripOperations/TaxiCenter.h"


class TaxiCenterTest : public ::testing::Test {
protected:
    Driver *d;
    TripInfo *ti;
    Cab *cab;
    TaxiCenter *tc;

    virtual void SetUp() {
        d = new Driver(305, 40, MartialStatues::WIDOWED, 7, 0);
        ti = new TripInfo(100, new Point(0, 0), new Point(3, 3), 1, 100);
        cab = new Cab(Color::GREEN, CarManufacture::TESLA, 0);
        tc = new TaxiCenter();
        tc->addTaxi(cab);
        tc->addDriver(d);
        tc->addTI(ti);
    }

    virtual void TearDown() {
        delete (tc);
    }
};

/**
 * checks the getEmployees method.
 * checks if the employees list correct.
 */
TEST_F(TaxiCenterTest, getEmployees) {
    std::list<Driver *> *drivers = tc->getEmployees();
    ASSERT_TRUE(*(drivers->front()) == *d)
                                << "Driver is not the driver in the TaxiCenter";
}

/**
 * checks the getAvailableDrivers method.
 * checks if the available list correct.
 */
TEST_F(TaxiCenterTest, getAvailableDrivers) {
    std::list<Driver *> *drivers = tc->getAvailableDrivers();
    ASSERT_TRUE(drivers->empty());
    Driver *d1 = new Driver(305, 40, MartialStatues::WIDOWED, 7, 1);
    Cab *cab1 = new Cab(Color::RED, CarManufacture::HONDA, 1);
    tc->addTaxi(cab1);
    tc->addDriver(d1);
    ASSERT_TRUE(*(drivers->front()) == *d1)
                                << "available Driver is not the driver in the TaxiCenter";
}

/**
 * checks the getDriverLocation method.
 * checks if the getDriverLocation returns the right location.
 */
TEST_F(TaxiCenterTest, getDriverLocation) {
    Point *location = tc->getDriverLocation(305);
    Point p(0, 0);
    ASSERT_TRUE(*location == p) << "Driver location is not (0,0)";
    location = tc->getDriverLocation(6);
    ASSERT_TRUE(location == NULL) << "no ID of 6 in the taxi center";
}

/**
 * checks the getTaxiByID method.
 * checks if the getTaxiByID returns the right cab.
 */
TEST_F(TaxiCenterTest, getTaxiByID) {
    Taxi *cab1 = tc->getTaxiByID(0);
    ASSERT_TRUE(*cab1 == *cab) << "same taxi, should be equal";
}

/**
 * checks the getClosestDriver method.
 * checks if the getClosestDriver returns the right driver.
 * the addTI uses the getclosestDriver to attach the TI into the right driver
 */
TEST_F(TaxiCenterTest, getClosestDriver) {
    Cab *cab1 = new Cab(Color::RED, CarManufacture::HONDA, 1);
    Driver *d1 = new Driver(305, 40, MartialStatues::WIDOWED, 7, 1);
    tc->addTaxi(cab1);
    tc->addDriver(d1);
    TripInfo *ti1 = new TripInfo(100, new Point(3, 3), new Point(4, 3), 1, 100);
    tc->moveAll();
    tc->addTI(ti1);
    tc->moveAll();
    Point p(4, 3);
    ASSERT_FALSE(*(cab1->getLocation()->getP()) == p) << "this taxi shouldn't have moved to (4,3)";
    ASSERT_TRUE(*(cab->getLocation()->getP()) == p) << "this taxi should have moved to (4,3)";
}

/**
 * checks the addDriver method.
 * checks if the driver got added.
 */
TEST_F(TaxiCenterTest, addDriver) {
    ASSERT_TRUE(*(tc->getEmployees()->front()) == *d);
}

/**
 * checks the addTaxi method.
 * checks if the Taxi got added.
 */
TEST_F(TaxiCenterTest, addTaxi) {
    ASSERT_TRUE(*(tc->getEmployees()->front()->getCab()) == *cab);
}

/**
 * checks the addTI method.
 * checks if the trip info got added.
 */
TEST_F(TaxiCenterTest, addTI) {
    ASSERT_TRUE(tc->getEmployees()->front()->getTi() != NULL);
    ASSERT_TRUE(*(tc->getEmployees()->front()->getTi()) == *ti);
}

/**
 * checks the setDriverToTi method.
 * checks if the driver recieved the trip info.
 */
TEST_F(TaxiCenterTest, setDriverToTi) {
    ASSERT_TRUE(*(tc->getEmployees()->front()->getTi()) == *ti);
}

/**
 * checks the moveAll method.
 * checks if the location of the cab changed after the movement.
 */
TEST_F(TaxiCenterTest, moveAll) {
    Point p(3, 3);
    ASSERT_TRUE(*(cab->getLocation()->getP()) != p);
    tc->moveAll();
    ASSERT_TRUE(*(cab->getLocation()->getP()) == p);
}