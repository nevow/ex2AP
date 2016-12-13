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
    if (ti->checkEnd(driver->getCab()->getLocation()->getP())) {
        ti.
        driver
    }
}

