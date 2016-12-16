//
// CoordinatedItem.
// abstract class
//

#ifndef EX1_COORDINATEDITEM_H
#define EX1_COORDINATEDITEM_H


class CoordinatedItem {
private:
    int distance;
    CoordinatedItem *parent;

public:
    virtual ~CoordinatedItem() {
        //delete (parent);
    };

    virtual int **getCoordinates() = 0;

    int getDistance() {
        return distance;
    }

    void setDistance(int d) {
        distance = d;
    }

    virtual void deleteCoords(int **coords) = 0;

    CoordinatedItem *getParent() {
        return parent;
    }

    void setParent(CoordinatedItem *p) {
        parent = p;
    }
};


#endif //EX1_COORDINATEDITEM_H
