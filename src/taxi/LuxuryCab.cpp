//
// Created by nevo on 01/12/16.
//

#include "LuxuryCab.h"

LuxuryCab::LuxuryCab(int tariff, const Color &color, const CarManufacture &firm, int kmPassed, int id, Node *location)
        : Taxi(tariff, color, firm, kmPassed, id, location) {}

/**
 *
 * @param road to move the cab according to
 */
void LuxuryCab::move(stack<CoordinatedItem *> *road) {

}
