//
// ProperInput.
//

#include <gtest/gtest-typed-test.h>
#include "ProperInput.h"

using namespace std;

/**
 * @return Point correct, after tests.
 */
Point ProperInput::validPoint(int columns, int rows) {
    Point point;
    char trash;
    cin >> point >> trash;

    // check if the point is in the map's boundary
    if ((point.getX() < columns) && (point.getY() < rows) &&
        (point.getX() >= 0) && (point.getY() >= 0)) {
        return point;
    } else {
        throw runtime_error("the point is not on the map boundaries");
    }
}

/**
 * @return int correct, after tests.
 */
int ProperInput::validInt() {
    int num;
    char trash;
    cin >> num >> trash;

    //check if the num is
    if (num >= 0) {
        return num;
    } else {
        throw runtime_error("negative number");
    }
}

/**
 * @return double correct, after tests.
 */
double ProperInput::validDouble() {
    double num;
    char trash;
    cin >> num >> trash;

    //check if the num is
    if (num >= 0) {
        return num;
    } else {
        throw runtime_error("negative number");
    }
}