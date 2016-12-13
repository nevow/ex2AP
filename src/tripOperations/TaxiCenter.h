//
// Created by nevo on 01/12/16.
//

#ifndef EX1_TAXICENTER_H
#define EX1_TAXICENTER_H


#include <list>
#include "Driver.h"
#include "../coordinates/Point.h"
#include "Passenger.h"
#include "../listeners/EventListener.h"

using namespace std;

class TaxiCenter {
private:
    list<Driver *> *employees;
    list<Node *> *locations;
    list<Taxi *> *cabs;
    list<TripInfo *> *trips;
    list<Driver *> *availableDrivers;
public:
    TaxiCenter(list<Driver *> *employees, list<Node *> *locations, list<Taxi *> *cabs, list<TripInfo *> *trips)
            : employees(employees), locations(locations), cabs(cabs), trips(trips),
              availableDrivers(employees) {}

    TaxiCenter() {
        employees = new list<Driver *>;
        locations = new list<Node *>;
        cabs = new list<Taxi *>;
        trips = new list<TripInfo *>;
        availableDrivers = new list<Driver *>;
    }

    ~TaxiCenter() {
        delete (employees);
        delete (locations);
        delete (cabs);
        delete (trips);
        delete (availableDrivers);
    }

    TripInfo *answerCall(Passenger *p);

    Driver *getAvailableDriver(TripInfo *ti);

    void sendTaxi(Driver *d);

    void moveAll();

    list<Driver *> *getAvailableDrivers() const;

    void addDriver(Driver *d);

    void addTaxi(Taxi *cab);
};


#endif //EX1_TAXICENTER_H
