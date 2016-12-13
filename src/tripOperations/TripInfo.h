//
// Created by nevo on 01/12/16.
//

#ifndef EX1_TRIPINFO_H
#define EX1_TRIPINFO_H


#include <stack>
#include "../coordinates/Point.h"
#include "Passenger.h"

class TripInfo {
private:
    int rideId;
    int currentDistance;
    Point* start;
    Point* destination;
    int amountOfPassengers;
    Passenger** passengers;
    stack<CoordinatedItem *> *road;
    int tariff;
public:
    TripInfo(int rideId, Point *start, Point *destination, int amountOfPassengers, Passenger **passengers, int tariff);

    bool checkEnd(Point* location);

    stack<CoordinatedItem *> * getRoad();



    bool operator==(const TripInfo &ti) const;

    bool operator!=(const TripInfo &ti) const;

    int getAmountOfPassengers() const;
};


#endif //EX1_TRIPINFO_H

