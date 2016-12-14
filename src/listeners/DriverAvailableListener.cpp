//
// Created by nevo on 01/12/16.
//

#include "DriverAvailableListener.h"

DriverAvailableListener::DriverAvailableListener(Driver *driver, TaxiCenter *tc) : driver(driver),
                                                                                   tc(tc) {}

/**
 * notify all
 */
void DriverAvailableListener::notify() {
    if (driver->getTi()->checkEnd(driver->getCab()->getLocation()->getP())) {
        tc->getAvailableDrivers()->push_back(driver);
    }
}