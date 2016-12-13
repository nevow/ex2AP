//
// Created by nevo on 01/12/16.
//

#include "TripEndListener.h"

/*
 * constructor
 */
TripEndListener::TripEndListener(Driver *driver, TripInfo *ti) : driver(driver), ti(ti) {}

/**
 * notify all
 */
void TripEndListener::notify() {
    list <Passenger> *qwe;
    //pass = ti->getPassengers();
    if (ti->checkEnd(driver->getCab()->getLocation()->getP())) {
        int passengerAmount = ti->getAmountOfPassengers();
        for (int i = 0; i < passengerAmount; i++) {
            driver->getSatisfaction()->update(3);
        }
    }
}

