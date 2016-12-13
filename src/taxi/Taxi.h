//
// Created by nevo on 01/12/16.
//

#ifndef EX1_TAXI_H
#define EX1_TAXI_H


#include "../enum/Color.h"
#include "../enum/CarManufacture.h"
#include "../coordinates/Node.h"
#include <stack>

class Taxi {
private:
    int tariff;
    Color color;
    CarManufacture firm;
    int kmPassed;
    int id;
    Node *location;
public:
    bool operator==(const Taxi &rhs) const {
        return id == rhs.id;
    }

    bool operator!=(const Taxi &rhs) const {
        return !(rhs == *this);
    }

public:
    Taxi(int tariff, const Color &color, const CarManufacture &firm, int kmPassed, int id, Node *location) : tariff(
            tariff), color(color), firm(firm), kmPassed(kmPassed), id(id), location(location) {}

    virtual void move(stack<CoordinatedItem *> *road) = 0;

    Node *getLocation() const {
        return location;
    }
};


#endif //EX1_TAXI_H
