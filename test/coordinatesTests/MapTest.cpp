//
// check Map Class.
//


#include <gtest/gtest.h>
#include "../../src/coordinates/Map.h"

/**
* check getValue method.
*/
TEST(getValue, MapTest) {
    Map m(3, 3);

    CoordinatedItem *item = m.getValue(1, 1);

    int *x = item->getCoordinates()[0];
    int *y = item->getCoordinates()[1];

    // checks the x coordinate
    EXPECT_EQ(*x, 1);
    // checks the y coordinate
    EXPECT_EQ(*y, 1);
}

/**
* check getAllNeighbours method.
*/
TEST(getAllNeighbours, MapTest) {
    Map map(3, 3);
    //CoordinatedItem *item = map.getValue(0, 0);
    CoordinatedItem **adj = map.getAllNeighbours(map.getValue(0, 0));

    int **p1 = adj[0]->getCoordinates();
    int **p2 = adj[1]->getCoordinates();
    int *x1 = p1[0];
    int *y1 = p1[1];
    int *x2 = p2[0];
    int *y2 = p2[1];

    EXPECT_EQ(*x1, 0);
    EXPECT_EQ(*y1, 1);
    EXPECT_EQ(*x2, 1);
    EXPECT_EQ(*y2, 0);
    delete (p1);
    delete (p2);
}


/**
* check setAll method.
*/
TEST(setAll, MapTest) {
    Map map(2, 2);
    map.setAll(5);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; ++j) {
            ASSERT_TRUE(map.getMatrix()[i][j]->getDistance() == 5);
        }
    }
}

/**
* check setItem (distance) method.
*/
TEST(setItem, MapTest) {
    Map map(3, 3);
    map.setItem(map.getMatrix()[1][1], 3);
    EXPECT_EQ(map.getMatrix()[1][1]->getDistance(), 3);
    EXPECT_NE(map.getMatrix()[1][1]->getDistance(), -1);
}


/**
* check getRoot method.
*/
TEST(getRoot, MapTest) {
    Map map(2, 2);
    Point p1(0, 0);
    Point p2(1, 1);

    // the map didn't initialize, in every node the distance is -1, (0,0) is the root
    EXPECT_EQ(*map.getRoot()->getP(), p1);

    map.setItem(map.getMatrix()[0][0], 2);
    map.setItem(map.getMatrix()[1][0], 1);
    map.setItem(map.getMatrix()[0][1], 1);
    map.setItem(map.getMatrix()[1][1], 0);
    // the map initialize, (1,1) is the root
    EXPECT_EQ(*map.getRoot()->getP(), p2);
}
