//
// TaxiCenter.
//

#include "TaxiCenter.h"

TripInfo *TaxiCenter::answerCall(Passenger *p) {
    return NULL;
}

/**
 * @param ti trip info to assign to the driver.
 * @return the driver after the set of the trip info.
 */
Driver *TaxiCenter::getAvailableDriver(TripInfo *ti) {
    // if there is no available driver return NULL
    if (availableDrivers->empty()) {
        return NULL;
    }
    // get available driver, assign him with the trip info and return him.
    Driver *d = availableDrivers->front();
    availableDrivers->pop_front();
    d->setTi(ti);
    return d;
}

/**
 * @param d is the driver to assign the taxi too and to send on his way.
 */
void TaxiCenter::sendTaxi(Driver *d) {
    int cabId = d->getVehicle_id();
    // iterate over all the cabs, search for the right id.
    for (Taxi *t : *cabs) {
        if (t->getId() == cabId) {
            d->setCab(t);
            return;
        }
    }
}

/**
 * iterate over all the drivers and tell them to move.
 */
void TaxiCenter::moveAll() {
    while (!locations->empty()) {
        delete (locations->front());
        locations->pop_front();
    }
    for (Driver *d : *employees) {
        d->moveOneStep();
        locations->push_front(d->getCab()->getLocation());
    }
}

/**
 * @return get the available drivers list.
 */
list<Driver *> *TaxiCenter::getAvailableDrivers() const {
    return availableDrivers;
}

/**
 * @param d driver to add to the employees list.
 */
void TaxiCenter::addDriver(Driver *d) {
    employees->push_back(d);
}

/**
 * @param cab to add to the cabs list.
 */
void TaxiCenter::addTaxi(Taxi *cab) {
    cabs->push_back(cab);
}

/**
 *
 * @param ti to add to the trips list.
 */
void TaxiCenter::addTI(TripInfo *ti) {
    trips->push_back(ti);
}

/**
 *
 * @param id od the driver
 * @return the location of the driver with the id
 */
Point *TaxiCenter::getDriverLocation(int id) {
    for (Driver *d : *employees) {
        if (d->getId() == id) {
            return d->getCab()->getLocation()->getP();
        }
    }
    return NULL;
}


