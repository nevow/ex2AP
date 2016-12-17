//
// check Map Class.
//

#include <gtest/gtest.h>
#include "../../src/coordinates/Map.h"

/**
 * setup.
 */
class MapTest : public ::testing::Test {
protected:
    Map *map;
    Point *p1;
    Point *p2;

    virtual void SetUp() {
        map = new Map(2, 2);
        p1 = new Point(0, 0);
        p2 = new Point(1, 1);
    }

    virtual void TearDown() {
        delete (map);
        delete (p1);
        delete (p2);
    }
};

/**
* check getRows method.
*/
TEST_F(MapTest, getRows) {
    EXPECT_EQ(map->getRows(), 2);
}

/**
* check getColumns method.
*/
TEST_F(MapTest, getColumns) {
    EXPECT_EQ(map->getColumns(), 2);
}

/**
* check getValue method.
*/
TEST_F(MapTest, getValue) {

    CoordinatedItem *item = map->getCoordinatedItem(1, 1);
    int **coords = item->getCoordinates();
    int x = *(coords[0]);
    int y = *(coords[1]);

    // checks the x coordinate
    EXPECT_EQ(x, 1);
    // checks the y coordinate
    EXPECT_EQ(y, 1);
    item->deleteCoords(coords);

}

/**
* check getRoot method.
*/
TEST_F(MapTest, getRoot) {

// the map didn't initialize, in every node the distance is -1, (0,0) is the root
    EXPECT_EQ(map->getRoot()->getP(), *p1);

    map->setItem(map->getCoordinatedItem(0, 0), 2);
    map->setItem(map->getCoordinatedItem(1, 0), 1);
    map->setItem(map->getCoordinatedItem(0, 1), 1);
    map->setItem(map->getCoordinatedItem(1, 1), 0);
// the map initialize, (1,1) is the root
    EXPECT_EQ(map->getRoot()->getP(), p2);
}

/**
* check setAll method.
*/
TEST_F(MapTest, setAll) {
    map->setAll(5);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; ++j) {
            ASSERT_TRUE(map->getCoordinatedItem(i, j)->getDistance() == 5);
        }
    }
}

/**
* check setItem (distance) method.
*/
TEST_F(MapTest, setItem) {
    map->setItem(map->getCoordinatedItem(1, 1), 3);
    EXPECT_NE(map->getCoordinatedItem(1, 1)->getDistance(), -1);
    EXPECT_EQ(map->getCoordinatedItem(1, 1)->getDistance(), 3);
}

/**
* check getAllNeighbours method.
*/
TEST_F(MapTest, getAllNeighbours) {
    CoordinatedItem **adj = map->getAllNeighbours(map->getCoordinatedItem(0, 0));

    int **p1 = adj[0]->getCoordinates();
    int **p2 = adj[1]->getCoordinates();
    int x1 = *(p1[0]);
    int y1 = *(p1[1]);
    int x2 = *(p2[0]);
    int y2 = *(p2[1]);

    EXPECT_EQ(x1, 0);
    EXPECT_EQ(y1, 1);
    EXPECT_EQ(x2, 1);
    EXPECT_EQ(y2, 0);
    (*adj)->deleteCoords(p1);
    (*adj)->deleteCoords(p2);
}
