//
// TripEndListener.
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
    std::list<Passenger *> *passengers = ti->getPassengers();
    if (ti->checkEnd(driver->getCab()->getLocation()->getP())) {
        for (std::list<Passenger *>::const_iterator iterator = passengers->begin(),
                     end = passengers->end(); iterator != end; ++iterator) {
            driver->getSatisfaction()->update((*iterator)->generateSatisfaction());
        }
    }
}

