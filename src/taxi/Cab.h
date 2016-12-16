//
// Cab.
//

#ifndef EX1_CAB_H
#define EX1_CAB_H


#include "Taxi.h"

class Cab : public Taxi {
public:
    Cab(const Color &color, const CarManufacture &firm, int id);

    ~Cab() {
        cout << "deleteing cab";
    };

    void move(stack<CoordinatedItem *> *road);

    void setTariff(int t);

};


#endif //EX1_CAB_H
