//
// LuxuryCab.
//

#ifndef EX1_LUXURYCAB_H
#define EX1_LUXURYCAB_H


#include "Taxi.h"

class LuxuryCab : public Taxi {
public:
    LuxuryCab(int tariff, const Color &color, const CarManufacture &firm, int kmPassed, int id, Node *location);

    void move(stack<CoordinatedItem *> *road);

};


#endif //EX1_LUXURYCAB_H
