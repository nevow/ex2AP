//
// Created by nevo on 01/12/16.
//

#ifndef EX1_DRIVERAVAILABLELISTENER_H
#define EX1_DRIVERAVAILABLELISTENER_H


#include "EventListener.h"
#include "../tripOperations/Driver.h"
#include "../tripOperations/TaxiCenter.h"

class DriverAvailableListener : EventListener{
private:
    Driver *driver;
    TaxiCenter *tc;
public:
    DriverAvailableListener(Driver *driver, TaxiCenter *tc);

    void notify();

};


#endif //EX1_DRIVERAVAILABLELISTENER_H
