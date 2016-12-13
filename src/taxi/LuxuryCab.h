//
// Created by nevo on 01/12/16.
//

#ifndef EX1_LUXURYCAB_H
#define EX1_LUXURYCAB_H


#include "Taxi.h"

class LuxuryCab : public Taxi {
public:
    LuxuryCab(const Color &color, const CarManufacture &firm, int id);

    void move(stack<CoordinatedItem *> *road);

};


#endif //EX1_LUXURYCAB_H
