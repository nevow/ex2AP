//
// Created by nevo on 04/12/16.
//

#include <gtest/gtest.h>
#include <stack>
#include "../../src/tripOperations/TaxiCenter.h"
#include "../../src/coordinates/Map.h"
#include "../../src/taxi/Cab.h"
#include "../../src/managment/SystemOperations.h"
#include "../../src/managment/BFS.h"

class SystemOperationsTest : public ::testing::Test {
protected:
    Node *obstacle;
    Node *start;
    Node *end;
    Driver *d;
    Passenger *pass;
    SystemOperations *so;
    Taxi *cab;
    Taxi *luxuryCab;

    virtual void SetUp() {
        Map* map = new Map(10,10);
        so = new SystemOperations(map,NULL);
        obstacle = new Node(new Point(2, 4));
        start = new Node(new Point(2, 3));
        end = new Node(new Point(3, 4));
        d = new Driver(305, 40, MartialStatues::WIDOWED, 7,0);
        cab = new Cab( Color::GREEN, CarManufacture::TESLA, 4453523);
        luxuryCab = new Cab( Color::GREEN, CarManufacture::TESLA, 4453523);
        pass = new Passenger(start->getP(), end->getP());
    }

    virtual void TearDown() {
        delete (so);
        delete (obstacle);
        delete (end);
        delete (d);
        delete (cab);
        delete (luxuryCab);
        delete (pass);
    }
};

/**
 * checks the addObstacle method.
 * checks if expected road is returned.
 */
TEST_F(SystemOperationsTest, addObstacle) {
    so->addObstacle(obstacle);
    stack<CoordinatedItem *> road;
    road.push(new Node(new Point(3, 4)));
    road.push(new Node(new Point(3, 3)));
    road.push(new Node(new Point(2, 3)));
    ASSERT_TRUE(road == *(BFS::use(so->getMap(), start, end)));
}

/**
 * checks the moveAllCab method.
 * checks if the cab moves as planned.
 */
TEST_F(SystemOperationsTest, moveAllCab) {
    Node n(new Point(3, 3));
    so->addObstacle(obstacle);
    so->addDriver(d);
    so->addTaxi(cab);
    so->connectCall(pass);
    so->moveAll();
    ASSERT_TRUE(*(cab->getLocation()) == n);
}

/**
 * checks the moveAllLuxuryCab method.
 * checks if the LuxuryCab moved as planned.
 */
TEST_F(SystemOperationsTest, moveAllLuxuryCab) {
    Node n(new Point(3, 4));
    so->addObstacle(obstacle);
    so->addDriver(d);
    so->addTaxi(luxuryCab);
    so->connectCall(pass);
    so->moveAll();
    ASSERT_TRUE(*(cab->getLocation()) == n);
}
