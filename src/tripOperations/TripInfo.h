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
    TripInfo(int rideId, Point *start, Point *destination, int amountOfPassengers, double tariff);

    ~TripInfo() {
        if (passengers) {
            while (!passengers->empty()) {
                delete (passengers->front());
                passengers->pop_front();
            }
            delete (passengers);
        }
        while (!road->empty()) {
            CoordinatedItem *c = road->top();
            road->pop();
            delete (c);
        }
        delete road;
        delete start;
        delete destination;
    }

    double getTariff() const;

    bool checkEnd(Point *location);

    stack<CoordinatedItem *> *getRoad();

    int getAmountOfPassengers() const;

    list<Passenger *> *getPassengers() const;

    Point *getStart() const;

    bool operator==(const TripInfo &ti) const;

    bool operator!=(const TripInfo &ti) const;

};

#endif //EX1_TRIPINFO_H

