//
// Node.
// inherit CoordinatedItem, has a point.
//

#include "Node.h"

/**
 * @return array with the coordinate of the point
 */
int **Node::getCoordinates() {
    int **coords = new int *[2];
    coords[0] = new int(p->getX());
    coords[1] = new int(p->getY());
    return coords;
}

/**
 *
 * @param coords to delete
 */
void Node::deleteCoords(int **coords) {
    p->deleteCoords(coords);
}

/**
 * @return the point of the node
 */
Point *Node::getP() {
    return p;
}

bool Node::operator==(const Node &rhs) const {
    return *p == *rhs.p;
}

bool Node::operator!=(const Node &rhs) const {
    return !(rhs == *this);
}
