//
// Created by nevo on 01/12/16.
//

#ifndef EX1_TRIPENDLISTENER_H
#define EX1_TRIPENDLISTENER_H


#include "EventListener.h"
#include "../tripOperations/Driver.h"

class TripEndListener : EventListener{
private:
    Driver *driver;
    TripInfo *ti;
public:
    TripEndListener(Driver *driver, TripInfo *ti);

    void notify();

};


#endif //EX1_TRIPENDLISTENER_H
