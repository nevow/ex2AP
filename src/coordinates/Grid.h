//
// Grid.
// an abstract class
//

#ifndef EX1_GRID_H
#define EX1_GRID_H

#include "CoordinatedItem.h"

class Grid {
/*private:
    CoordinatedItem root;*/
public:
    virtual CoordinatedItem **getAllNeighbours(CoordinatedItem *item) = 0;

    virtual CoordinatedItem *getRoot() = 0;

    virtual CoordinatedItem *getValue(int r, int c) = 0;

    virtual void setAll(int dist) = 0;

    virtual void setItem(CoordinatedItem *item, int dist) = 0;

};


#endif //EX1_GRID_H
