//
// tripEndListenerTest.
// in charge to update the Passenger's Satisfaction on the Driver at the end of the trip.
// moves the driver to the available list
//

#include <gtest/gtest.h>
#include "../../src/taxi/Cab.h"
#include "../../src/tripOperations/Driver.h"
#include "../../src/tripOperations/TaxiCenter.h"

class tripEndListenerTest : public ::testing::Test {
protected:
    Point *start;
    Point *destination;
    Driver *d;
    Taxi *cab;
    TaxiCenter *tc;
    TripInfo *ti;

    /**
     * set points for the trip info
     * creates a taxi center, driver, cab and tripinfo
     */
    virtual void SetUp() {
        start = new Point(0, 0);
        destination = new Point(2, 3);
        tc = new TaxiCenter();
        cab = new Cab(Color::RED, CarManufacture::HONDA, 0);
        tc->addTaxi(cab);
        d = new Driver(100, 40, MartialStatues::SINGLE, 10, 0);
        tc->addDriver(d);                            // adds a tripEndListener to the taxi center
        ti = new TripInfo(0, start, destination, 3, 20);
        tc->addTI(ti);
    }

    virtual void TearDown() {
        delete (tc);
    }
};

/**
 * checks the notify method of the listener.
 * checks if set the driver satisfaction correctly.
 * checks if the get closest driver returns the recently free driver
 */
TEST_F(tripEndListenerTest, notify) {
    ASSERT_TRUE(d->getSatisfaction()->getAverage() == 0);
    tc->moveAll();
    EXPECT_TRUE(d->getSatisfaction()->getAverage() > 0);
    Point p(2, 3);
    Driver *dr = tc->getClosestDriver(&p);
    ASSERT_TRUE(dr != NULL);
    delete (dr);
}