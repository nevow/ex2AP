//
// Created by nevo on 03/12/16.
//

#include <gtest/gtest.h>
#include "../../src/taxi/Cab.h"
#include "../../src/tripOperations/Driver.h"
#include "../../src/tripOperations/TaxiCenter.h"
#include "../../src/listeners/DriverAvailableListener.h"

class driverAvailableTest : public ::testing::Test {
protected:
    Driver *d;
    TaxiCenter *tc;
    DriverAvailableListener *dal;

    virtual void SetUp() {
        d = new Driver(100, 40, MartialStatues::SINGLE, 10);
        tc = new TaxiCenter();
        dal = new DriverAvailableListener(d, tc);
    }

    virtual void TearDown() {
        delete (d);
        delete (tc);
        delete (dal);
    }
};

/**
 * checks the notify method of the listener.
 * checks if set the driver as available.
 */
TEST_F(driverAvailableTest, notify) {
    dal->notify();
    std::list<Driver *> *drivers = tc->getAvailableDrivers();
    ASSERT_TRUE(drivers != NULL);
    Driver *driver = drivers->front();
    ASSERT_TRUE(*driver == *d);
}