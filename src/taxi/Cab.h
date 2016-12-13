//
// Created by nevo on 01/12/16.
//

#ifndef EX1_CAB_H
#define EX1_CAB_H


#include "Taxi.h"

class Cab : public Taxi {
public:
    Cab(int tariff, const Color &color, const CarManufacture &firm, int kmPassed, int id, Node *location);

    void move(stack<CoordinatedItem *> * road);

};


#endif //EX1_CAB_H