//
// Created by nevo on 01/12/16.
//

#include "Cab.h"

Cab::Cab(int tariff, const Color &color, const CarManufacture &firm, int kmPassed, int id, Node *location) : Taxi(
        tariff, color, firm, kmPassed, id, location) {

}

void Cab::move(stack<CoordinatedItem *> *road) {

}
