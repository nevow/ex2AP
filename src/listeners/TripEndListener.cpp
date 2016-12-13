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
    std::list<Passenger *> *passenger;
    passenger = ti->getPassengers();
    if (ti->checkEnd(driver->getCab()->getLocation()->getP())) {
        for (Passenger *p : *passenger) {
            driver->getSatisfaction()->update(p->generateSatisfaction());
        }
    }
}

