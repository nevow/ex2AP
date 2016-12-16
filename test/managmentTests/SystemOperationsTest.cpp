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
 */
class SystemOperationsTest : public ::testing::Test {
protected:
    Node *start;
    Node *end;
    Node *obstacle;
    list<Node *> *obstacles;
    Driver *d;
    Passenger *pass;
    SystemOperations *so;
    Taxi *cab;
    Taxi *luxuryCab;
    TaxiCenter *tc;


    virtual void SetUp() {
        Map *map = new Map(10, 10);
        so = new SystemOperations(map, obstacles);
        obstacle = new Node(new Point(2, 4));
        start = new Node(new Point(2, 3));
        end = new Node(new Point(3, 4));
        d = new Driver(305, 40, MartialStatues::WIDOWED, 7, 0);
        cab = new Cab(Color::GREEN, CarManufacture::TESLA, 4453523);
        luxuryCab = new Cab(Color::GREEN, CarManufacture::TESLA, 4453523);
        pass = new Passenger(start->getP(), end->getP());

        tc = new TaxiCenter(new std::list<Driver *>, new std::list<Node *>,
                            new std::list<Taxi *>, new std::list<TripInfo *>);
    }

    virtual void TearDown() {
        delete (so);
        delete (end);
        delete (start);
        delete (obstacle);
        delete (obstacles);
        delete (d);
        delete (cab);
        delete (luxuryCab);
        delete (pass);
    }
};

/**
 * checks getMap method.
 */
TEST_F(SystemOperationsTest, getMap) {

    Map *map1 = new Map(4, 4);
    SystemOperations *so1 = new SystemOperations(map1, NULL);
    Map *map2 = so1->getMap();

    ASSERT_EQ(map1, map2);
}

/**
 * checks the addObstacle method.
 */
TEST_F(SystemOperationsTest, addObstacle) {
    so->addObstacle(obstacle);
    ASSERT_EQ (obstacles->front(), obstacle);
}

/**
 * the methods addDriver, addTaxi and addTI have been tested at TaxiCenter.
 * all the three are "stupid methods" that call TaxiCenter's methods.
 */

/**
 * checks the getDriverLocation method.
 */
TEST_F(SystemOperationsTest, getDriverLocation) {
    Driver *d1 = new Driver(304, 21, MartialStatues::SINGLE, 2, 0);
    d1->setCab(cab);
    tc->addDriver(d);
    tc->addDriver(d1);

    ASSERT_EQ (so->getDriverLocation(305), cab->getLocation());
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
