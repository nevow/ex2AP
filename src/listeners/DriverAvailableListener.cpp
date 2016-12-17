// DriverAvailableListener.
// has taxi center and driver.
// in charge to update the available drivers list when driver finish his ride.

#include "DriverAvailableListener.h"

/**
 * constructor.
 * @param driver of the listener (to listen to)
 * @param tc of the listener (to update)
 */
DriverAvailableListener::DriverAvailableListener(Driver *driver, TaxiCenter *tc) : driver(driver),
                                                                                   tc(tc) {}

/**
 * notify all.
 * if the driver arrived to his end point, add him to the available drivers list.
 */
void DriverAvailableListener::notify() {
    TripInfo *ti = driver->getTi();
    if (!ti) {
        return;
    }
    if (ti->checkEnd(driver->getCab()->getLocation()->getP())) {
        std::list<Driver *> *drivers = tc->getEmployees();
        std::list<Driver *> tempDrivers;
        Driver *d;
        for (std::list<Driver *>::const_iterator iterator = drivers->begin(), end = drivers->end();
             iterator != end; ++iterator) {
            if ((*iterator)->getId() == driver->getId()) {
                drivers->pop_front();
                while (!tempDrivers.empty()) {
                    d = tempDrivers.front();
                    tempDrivers.pop_front();
                    drivers->push_front(d);
                }
                break;
            } else {
                d = drivers->front();
                drivers->pop_front();
                tempDrivers.push_front(d);
            }
        }
        tc->getAvailableDrivers()->push_back(driver);
        delete (ti);
        driver->setTi(NULL);
    }
}