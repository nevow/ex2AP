//
// TripEndListener.
// in charge to update the Passenger's Satisfaction on the Driver at the end of the trip.
//

#include "TripEndListener.h"

/*
 * constructor.
 */
TripEndListener::TripEndListener(Driver *driver, TripInfo *ti) : driver(driver), ti(ti) {}

/**
 * not relevant yet. at this part of the program there is no usage at passengers.
 * if the driver arrived to his end point, get Satisfaction from each passengers.
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

