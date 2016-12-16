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
    SystemOperations(Map *map1, list<Node *> *obs) {
        map = map1;
        obstacles = obs;
        tc = new TaxiCenter();
    }

    ~SystemOperations() {
        delete (map);
        delete (tc);
        //obstacles->clear();
        delete (obstacles);
    }

    void addObstacle(Node *obstacle);

    void addDriver(Driver *d);

    void addTaxi(Taxi *cab);

    void addTI(TripInfo *tripInfo);

    Map *getMap() const;

    Point *getDriverLocation(int id);

    void moveAll();

    void connectCall(Passenger *p);
};


#endif //EX1_SYSTEMOPERATIONS_H
