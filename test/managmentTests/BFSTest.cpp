//
// Created by nevo on 05/12/16.
//


#include <gtest/gtest.h>
#include <stack>
#include "../../src/tripOperations/TaxiCenter.h"
#include "../../src/coordinates/Map.h"
#include "../../src/managment/BFS.h"

class BFSTest : public ::testing::Test {
protected:
    Map *map;
    stack<CoordinatedItem *> *road;
    Node* start;
    Node* end;


    virtual void SetUp() {
        map = new Map(3, 3);
        start = new Node(new Point(0,0));
        end = new Node(new Point(2,2));
        road = new stack<CoordinatedItem *>;
        road->push(new Node(new Point(2,2)));
        road->push(new Node(new Point(2,1)));
        road->push(new Node(new Point(2,0)));
        road->push(new Node(new Point(1,0)));
        road->push(new Node(new Point(0,0)));
    }


    virtual void TearDown() {
        delete(start);
        delete(end);
        delete (map);
        delete (road);
    }
};

/**
 * checks the use method.
 * checks if expected road is returned.
 */
TEST_F(BFSTest, use) {
    ASSERT_TRUE(*road == *(BFS::use(map, start, end)));
}

/**
 * checks the BFSAlgo method.
 * validates that every node in the map received the right distance.
 */
TEST_F(BFSTest, BFSAlgo) {
    BFS::BFSAlgo(map, start);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3 ; ++j) {
            ASSERT_TRUE(map->getMatrix()[i][j]->getDistance() == i + j );
        }
    }
}

/**
 * checks the getTrip method.
 * checks if expected road is returned.
 */
TEST_F(BFSTest, getTrip) {

    BFS::BFSAlgo(map, end);
    ASSERT_TRUE(*BFS::getTrip(end) == *road);

}


