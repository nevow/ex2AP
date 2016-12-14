//
// Created by nevo on 04/12/16.
//
#include <list>
#include <gtest/gtest.h>
#include "../../src/taxi/Cab.h"
#include "../../src/tripOperations/TaxiCenter.h"


class TaxiCenterTest : public ::testing::Test {
protected:
    Point *start;
    Point *destination;
    Node *location;
    Node *endLocation;
    Passenger *pass;
    list<Passenger *> *passengers;
    Driver *d;
    TripInfo *ti;
    Cab *cab;
    TaxiCenter *tc;

    virtual void SetUp() {
        start = new Point(3, 3);
        destination = new Point(4, 3);
        location = new Node(start);
        endLocation = new Node(destination);
        pass = new Passenger(start, destination);
        passengers = new list<Passenger *>;
        passengers->push_front(pass);
        d = new Driver(305, 40, MartialStatues::WIDOWED, 7, 0);
        ti = new TripInfo(100, start, destination, 1, passengers,
                          100);          // standard first trip info
        cab = new Cab(Color::GREEN, CarManufacture::TESLA, 4453523);
        tc = new TaxiCenter();
    }

    virtual void TearDown() {
        delete (location);
        delete (endLocation);
        delete (pass);
        delete (d);
        delete (ti);
        delete (cab);
        delete (tc);
    }
};

/**
 * checks the answerCall method.
 * checks if the TripInfo that was created it the right one.
 */
TEST_F(TaxiCenterTest, answerCall) {
    ASSERT_TRUE(ti == tc->answerCall(pass))
                                << "trip info differs in id, start point or destination";
}

/**
 * checks the getAvailableDriver method.
 * checks if the driver got added to the right list.
 */
TEST_F(TaxiCenterTest, getAvailableDriver) {
    tc->addDriver(d);
    d->setTi(ti);
//    ASSERT_TRUE(d == tc->setDriverToTi(ti)) << "available Driver is not the driver in the TaxiCenter";
}

/**
 * checks the sendTaxi method.
 * checks if the connection between the driver and the cab was done properly.
 */
TEST_F(TaxiCenterTest, sendTaxi) {
    tc->addTaxi(cab);
    tc->addDriver(d);
    ASSERT_TRUE(d->getCab() != cab) << "no cab assigned to driver yet";
//    tc->sendTaxi(d);
    EXPECT_TRUE(d->getCab() == cab) << "same cab, should be equal";
}

/**
 * checks the moveAll method.
 * checks if the location of the cab changed after the movement.
 */
TEST_F(TaxiCenterTest, moveAll) {
    d->setTi(ti);
    tc->addTaxi(cab);
    tc->addDriver(d);
//    tc->sendTaxi(d);
    tc->moveAll();
    ASSERT_TRUE(cab->getLocation()->getP() != start);
}

/**
 * checks the getAvailableDrivers method.
 * checks if the drivers list is being properly managed.
 */
TEST_F(TaxiCenterTest, getAvailableDrivers) {
    Driver *d1 = new Driver(304, 21, MartialStatues::SINGLE, 2, 0);
    tc->addDriver(d);
    tc->addDriver(d1);
    std::list<Driver *> *drivers = tc->getAvailableDrivers();
    EXPECT_TRUE(*(drivers->front()) == *d);
    drivers->pop_front();
    EXPECT_TRUE(*(drivers->front()) == *d1);
    delete (d1);
}

