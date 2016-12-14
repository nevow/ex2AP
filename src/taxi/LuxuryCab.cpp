//
// LuxuryCab.
//

#include "LuxuryCab.h"

LuxuryCab::LuxuryCab(const Color &color, const CarManufacture &firm, int id)
        : Taxi(color, firm, id) {}

/**
 *
 * @param road to move the cab according to
 */
void LuxuryCab::move(stack<CoordinatedItem *> *road) {
    if (!road->empty()) {
        CoordinatedItem *item = road->top();
        road->pop();
        if (!road->empty()) {
            item = road->top();
            road->pop();
        }
        int **coords = item->getCoordinates();
        Point *p = new Point(*(coords[0]), *(coords[1]));
        p->deleteCoords(coords);
        applyToPoint(p);
    }
}

/**
 *
 * @param t is the tariff of the taxi
 */
void LuxuryCab::setTariff(int t) {
    Taxi::setTariff(t * 2);
}
