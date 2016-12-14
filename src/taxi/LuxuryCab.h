//
// LuxuryCab.
//

#ifndef EX1_LUXURYCAB_H
#define EX1_LUXURYCAB_H


#include "Taxi.h"

class LuxuryCab : public Taxi {
public:
    LuxuryCab(const Color &color, const CarManufacture &firm, int id);

    void move(stack<CoordinatedItem *> *road);

    void setTariff(int t);

};


#endif //EX1_LUXURYCAB_H
