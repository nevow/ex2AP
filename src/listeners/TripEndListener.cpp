//
// Created by nevo on 01/12/16.
//

#include "TripEndListener.h"

void TripEndListener::notify() {

}

TripEndListener::TripEndListener(Driver *driver, TripInfo *ti) : driver(driver), ti(ti) {}
