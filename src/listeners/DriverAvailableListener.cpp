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
    if (driver->getTi()->checkEnd(driver->getCab()->getLocation()->getP())) {
        tc->getAvailableDrivers()->push_back(driver);
        delete (driver->getTi());
    }
}