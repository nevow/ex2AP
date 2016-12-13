//
// Satisfaction.
//

#include "Satisfaction.h"

/**
 * constructor.
 */
Satisfaction::Satisfaction() {
    amount = 0;
    average = 0;
}

/**
 *
 * @return the average satisfaction.
 */
double Satisfaction::getAverage() const {
    return average;
}

/**
 *
 * @param grade to add to the average grade.
 */
void Satisfaction::update(int grade) {
    average = ((average * amount) + grade) / (amount + 1);
    amount++;
}

