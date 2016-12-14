//
// Created by nevo on 03/12/16.
//

#include <gtest/gtest.h>
#include "../../src/taxi/Cab.h"
#include "../../src/tripOperations/Driver.h"
#include "../../src/tripOperations/TaxiCenter.h"
#include "../../src/listeners/TripEndListener.h"

class tripEndListenerTest : public ::testing::Test {
protected:
    Point *p1;
    Point *p2;
    Node *n;
    Driver *d;
    Taxi *cab;
    TaxiCenter *tc;
    Passenger *pa;
    TripInfo *ti;
    TripEndListener *tel;

    virtual void SetUp() {
        p1 = new Point(3, 3);
        p2 = new Point(2, 3);
        n = new Node(p1);
        d = new Driver(100, 40, MartialStatues::SINGLE, 10,0);
        cab = new Cab( Color::RED, CarManufacture::HONDA, 1306410);
        pa = new Passenger(p1, p2);
        tc = new TaxiCenter();
        ti = tc->answerCall(pa);
        tc->addTaxi(cab);
        tc->addDriver(d);
        tel = new TripEndListener(d, ti);
    }

    virtual void TearDown() {
        delete (p2);
        delete (n);
        delete (ti);
        delete (pa);
        delete (tel);
        delete (tc);
    }
};

/**
 * checks the notify method of the listener.
 * checks if set the driver satisfaction correctly.
 */
TEST_F(tripEndListenerTest, notify) {
//    tc->sendTaxi(d);
    d->moveOneStep();
    ASSERT_TRUE(d->getSatisfaction()->getAverage() == 0);
    tel->notify();
    EXPECT_TRUE(d->getSatisfaction()->getAverage() > 0);
}