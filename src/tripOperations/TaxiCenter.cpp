//
// TaxiCenter.
//

#include "TaxiCenter.h"

TripInfo *TaxiCenter::answerCall(Passenger *p) {
    return NULL;
}

/**
 *
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

void TaxiCenter::sendTaxi(Driver *d) {
    int cab_id = d->getVehicle_id();
    d->setCab(cabs->front());
}

void TaxiCenter::moveAll() {
    for (Driver *d : *employees) {
        d->moveOneStep();
    }
}

/**
 *
 * @return get the available drivers list.
 */
list<Driver *> *TaxiCenter::getAvailableDrivers() const {
    return availableDrivers;
}

/**
 *
 * @param d driver to add to the employees list.
 */
void TaxiCenter::addDriver(Driver *d) {
    employees->push_back(d);
}

/**
 *
 * @param cab to add to the cabs list.
 */
void TaxiCenter::addTaxi(Taxi *cab) {
    cabs->push_back(cab);
}


