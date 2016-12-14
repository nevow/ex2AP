//
// Created by nevo on 01/12/16.
//

#include "SystemOperations.h"


void SystemOperations::addObstacle(Node *obstacle) {
    obstacles->push_back(obstacle);
}


void SystemOperations::addDriver(Driver *d) {
    tc->addDriver(d);
}

void SystemOperations::addTaxi(Taxi *cab) {
    tc->addTaxi(cab);

}

void SystemOperations::addTI(TripInfo *tripInfo) {
    tc->addTI(tripInfo);

}

Point *SystemOperations::getDriverLocation(int id) {
    return tc->getDriverLocation(id);
}


Map *SystemOperations::getMap() const {
    return map;
}

void SystemOperations::moveAll() {
    tc->moveAll();
}

void SystemOperations::connectCall(Passenger *p) {

}
