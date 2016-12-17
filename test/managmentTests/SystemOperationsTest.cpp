//
// SystemOperationsTest.
//

#include <gtest/gtest.h>
#include <stack>
#include "../../src/tripOperations/TaxiCenter.h"
#include "../../src/coordinates/Map.h"
#include "../../src/taxi/Cab.h"
#include "../../src/managment/SystemOperations.h"

/*
 * setup.
 * notice that all of SystemOperations methods for now are using Taxi-Center methods.
 * so it got no reason to test taxi center again.
 */
class SystemOperationsTest : public ::testing::Test {
protected:
    Node *obstacle1;
    Node *obstacle2;
    list<Node *> *obstacles;
    SystemOperations *so;


    virtual void SetUp() {
        Map *map = new Map(5, 8);
        obstacles = new list<Node *>;
        Point p1(2, 2);
        Point p2(3, 1);
        obstacle1 = new Node(&p1);
        obstacle2 = new Node(&p2);
        obstacles->push_front(obstacle1);
        obstacles->push_back(obstacle2);
        so = new SystemOperations(map, obstacles);
    }

    virtual void TearDown() {
        delete (so);
        delete (obstacle1);
        delete (obstacle2);
    }
};

/**
 * checks the getX method.
 */
TEST_F(SystemOperationsTest, getX) {
    ASSERT_TRUE(so->getX() == 5);
}

/**
 * checks the getY method.
 */
TEST_F(SystemOperationsTest, getY) {
    ASSERT_TRUE(so->getY() == 8);
}

/**
 * checks the addObstacle method.
 */
/*TEST_F(SystemOperationsTest, addObstacle) {
    ASSERT_TRUE(obstacles->front() == obstacle1);
    obstacles->pop_front();
    ASSERT_TRUE(obstacles->front() == obstacle2);
    obstacles->pop_front();
    ASSERT_TRUE(obstacles->empty());
}*/
