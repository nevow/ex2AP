//
// Created by nevo on 01/12/16.
//

#ifndef EX1_SYSTEMOPERATIONS_H
#define EX1_SYSTEMOPERATIONS_H

#include <list>
#include "../coordinates/Node.h"
#include "../tripOperations/TaxiCenter.h"
#include "../coordinates/Map.h"
#include "../listeners/EventListener.h"

using namespace std;

class SystemOperations {
private:
    int x;
    int y;
    list<Node *> *obstacles;
    TaxiCenter *tc;
    Map *map;
public:
    SystemOperations(int x, int y) {
        map = new Map(x, y);
        tc = new TaxiCenter();
    }

    void addObstacle(Node *obstacle);

    void addDriver(Driver *d);

    void addTaxi(Taxi *cab);

    Map *getMap() const;

    void moveAll();

    void connectCall(Passenger *p);
};


#endif //EX1_SYSTEMOPERATIONS_H
