// DriverAvailableListener.
// has taxi center and driver.
// in charge to update the available drivers list when driver finish his ride.

#ifndef EX1_DRIVERAVAILABLELISTENER_H
#define EX1_DRIVERAVAILABLELISTENER_H


#include "EventListener.h"
#include "../tripOperations/Driver.h"
#include "../tripOperations/TaxiCenter.h"

class DriverAvailableListener : public EventListener {
private:
    Driver *driver;
    TaxiCenter *tc;
public:
    DriverAvailableListener(Driver *driver, TaxiCenter *tc);

    void notify();


};


#endif //EX1_DRIVERAVAILABLELISTENER_H
