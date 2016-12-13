//
// Created by nevo on 01/12/16.
//

#include "Cab.h"

Cab::Cab(const Color &color, const CarManufacture &firm, int id) : Taxi(color, firm, id) {
}

void Cab::move(stack<CoordinatedItem *> *road) {
    CoordinatedItem *item = road->top();
    road->pop();
    int **coords = item->getCoordinates();
    Point *p = new Point(*(coords[0]), *(coords[1]));
    p->deleteCoords(coords);
    applyToPoint(p);
}
