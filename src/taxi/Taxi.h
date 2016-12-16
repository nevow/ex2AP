//
// Taxi.
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
    Taxi(const Color &color, const CarManufacture &firm, int id) : color(color), firm(firm),
                                                                   kmPassed(0), id(id),
                                                                   location(new Node(
                                                                           new Point(0, 0))) {}

    virtual ~Taxi() {
        cout << "deleteing taxi";
        delete (location);
    };

    virtual void move(stack<CoordinatedItem *> *road) = 0;

    /**
     *
     * @return the location of the taxi
     */
    Node *getLocation() const {
        return location;
    }

    /**
     *
     * @return the id of the Taxi.
     */
    int getId() const {
        return id;
    }

    virtual void setTariff(int t) {
        tariff = t;
    };


    void applyToPoint(Point *p) {
        delete (location->getP());
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
