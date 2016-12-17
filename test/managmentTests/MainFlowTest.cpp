//
// MainFlow.
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
class MainFlowTest : public ::testing::Test {
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

TEST_F(MainFlowTest, input) {

    Map *map1 = new Map(4, 4);
    SystemOperations *so1 = new SystemOperations(map1, NULL);
    Map *map2 = so1->getMap();

    ASSERT_EQ(map1, map2);
}*/