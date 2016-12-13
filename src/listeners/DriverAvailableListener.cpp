//
// Created by nevo on 01/12/16.
//

#include "DriverAvailableListener.h"

void DriverAvailableListener::notify() {

}

DriverAvailableListener::DriverAvailableListener(Driver *driver, TaxiCenter *tc) : driver(driver), tc(tc) {}
