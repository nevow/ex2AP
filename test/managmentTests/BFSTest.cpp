//
// BFSTest.
//

#include <gtest/gtest.h>
#include <stack>
#include "../../src/tripOperations/TaxiCenter.h"
#include "../../src/coordinates/Map.h"
#include "../../src/managment/BFS.h"

/*
 * setup
 */
class BFSTest : public ::testing::Test {
protected:
    Map *map;
    stack<CoordinatedItem *> *road;
    Node *start;
    Node *end;

    virtual void SetUp() {
        map = new Map(3, 3);
        start = new Node(new Point(0, 0));
        end = new Node(new Point(2, 2));
        road = new stack<CoordinatedItem *>;
        Point p(2, 2);
        Point p1(2, 1);
        Point p2(2, 0);
        Point p3(1, 0);
        Point p4(0, 0);
        road->push(new Node(&p));
        road->push(new Node(&p1));
        road->push(new Node(&p2));
        road->push(new Node(&p3));
        road->push(new Node(&p4));
    }

    virtual void TearDown() {
        delete (start);
        delete (end);
        delete (map);
        delete (road);
    }
};

/**
 * checks the use method.
 * checks if expected road is returned.
 */
TEST_F(BFSTest, use) {
    stack<CoordinatedItem *> r = *(BFS::use(map, start, end));
    while (!r.empty() || !road->empty()) {
        if (!r.empty() && !road->empty()) {
            CoordinatedItem *item = road->top();
            int **coords1 = item->getCoordinates();
            int **coords2 = r.top()->getCoordinates();
            int x1 = *(coords1[0]);
            int y1 = *(coords1[1]);
            int x2 = *(coords2[0]);
            int y2 = *(coords2[1]);
            item->deleteCoords(coords1);
            item->deleteCoords(coords2);
            ASSERT_TRUE(x1 == x2);
            ASSERT_TRUE(y1 == y2);
            road->pop();
            r.pop();
        } else {
            return;
        }
    }
}

/**
 * checks the BFSAlgo method.
 * validates that every node in the map received the right distance.
 */
TEST_F(BFSTest, BFSAlgo) {
    BFS::BFSAlgo(map, start);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_TRUE(map->getCoordinatedItem(i, j)->getDistance() == i + j);
        }
    }
}

/**
 * checks the getTrip method.
 * checks if expected road is returned.
 */
TEST_F(BFSTest, getTrip) {

    BFS::BFSAlgo(map, start);
    stack<CoordinatedItem *> r = *BFS::getTrip(end);
    while (!r.empty() || !road->empty()) {
        if (!r.empty() && !road->empty()) {
            CoordinatedItem *item = road->top();
            int **coords1 = item->getCoordinates();
            int **coords2 = r.top()->getCoordinates();
            int x1 = *(coords1[0]);
            int y1 = *(coords1[1]);
            int x2 = *(coords2[0]);
            int y2 = *(coords2[1]);
            item->deleteCoords(coords1);
            item->deleteCoords(coords2);
            ASSERT_TRUE(x1 == x2);
            ASSERT_TRUE(y1 == y2);
            road->pop();
            r.pop();
        } else {
            return;
        }
    }
}


