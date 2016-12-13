//
// Created by nevo on 01/12/16.
//

#include "Cab.h"

Cab::Cab(int tariff, const Color &color, const CarManufacture &firm, int id) : Taxi(
        tariff, color, firm, id) {
}

void Cab::move(stack<CoordinatedItem *> *road) {

}
