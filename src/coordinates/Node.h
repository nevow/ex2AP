//
// Node.
// inherit CoordinatedItem, has a point.
//

#ifndef EX1_NODE_H
#define EX1_NODE_H

#include "Point.h"

class Node : public CoordinatedItem {
private:
    Point *p;

public:
    Node() {};

    Node(Point *p) : p(p) {
        setDistance(-1);
    }

    ~Node() {
        delete (p);
    }

    int **getCoordinates();

    void deleteCoords(int **coords);

    Point *getP();

    bool operator==(const Node &otherNode) const;

    bool operator!=(const Node &rhs) const;

    void setP(Point *p);
};


#endif //EX1_NODE_H
