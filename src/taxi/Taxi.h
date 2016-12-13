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
    /**
     *
     * @param tariff of the taxi
     * @param color of the taxi
     * @param firm of the taxi
     * @param id of the taxi
     * @param location of the taxi
     */
    Taxi(int tariff, const Color &color, const CarManufacture &firm, int id) : tariff(
            tariff), color(color), firm(firm), kmPassed(0), id(id), location(new Node(new Point(0, 0))) {}

    virtual void move(stack<CoordinatedItem *> *road) = 0;

    Node *getLocation() const {
        return location;
    }

    void applyToPoint(Point *p) {
        location->setP(p);
    }

    /**
     *
     * @param otherTaxi to compare this taxi to
     * @return true if the taxi are the same
     */
    bool operator==(const Taxi &otherTaxi) const {
        return id == otherTaxi.id;
    }

    /**
     *
     * @param otherTaxi to compare this taxi to
     * @return false if the taxi are the same
     */
    bool operator!=(const Taxi &otherTaxi) const {
        return !(otherTaxi == *this);
    }

};


#endif //EX1_TAXI_H
