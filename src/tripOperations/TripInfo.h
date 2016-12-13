//
// Created by nevo on 01/12/16.
//

#ifndef EX1_TRIPINFO_H
#define EX1_TRIPINFO_H


#include <stack>
#include <list>
#include "../coordinates/Point.h"
#include "Passenger.h"

class TripInfo {
private:
    int rideId;
    int currentDistance;
    Point *start;
    Point *destination;
    int amountOfPassengers;
    list<Passenger *> *passengers;
    stack<CoordinatedItem *> *road;
    double tariff;
public:
    TripInfo(int rideId, Point *start, Point *destination, int amountOfPassengers,
             list<Passenger *> *passengers, double tariff);

    bool checkEnd(Point *location);

    stack<CoordinatedItem *> *getRoad();

    int getAmountOfPassengers() const;

    list<Passenger *> *getPassengers() const;

    bool operator==(const TripInfo &ti) const;

    bool operator!=(const TripInfo &ti) const;

};

#endif //EX1_TRIPINFO_H

