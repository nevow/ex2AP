//
// Created by nevo on 01/12/16.
//


#include "MainFlow.h"

#include "../enum/MartialStatuesFactory.h"
#include "../taxi/Cab.h"
#include "../enum/ColorFactory.h"
#include "../enum/CarManufactureFactory.h"
#include "../taxi/LuxuryCab.h"


using namespace std;

MainFlow::MainFlow() {

}

void MainFlow::initialize() {

    int rows, columns, obstacleNum;

    std::list<Node *> *obstacles = new list<Node *>;

    // get the map's size and create it
    cin >> rows >> columns;
    Map *map = new Map(columns, rows);
    cin.ignore();

    cin >> obstacleNum;
    cin.ignore();

    for (; obstacleNum > 0; obstacleNum--) {
        Point obs(0, 0);
        cin >> obs;
        cin.ignore();
        Node n(&obs);
        obstacles->push_front(&n);
    }

    so = new SystemOperations(map, obstacles);
}

/**
 * get inputs from user
 */
void MainFlow::input() {
    int choice;
    int id, age, experience, vehicleId, taxi_type;
    int x_start, y_start, x_end, y_end, num_passengers;
    double tariff;
    char trash, status, manufacturer, color;

    do {
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
//********************** להוסיף getCab
                cin >> id >> trash >> age >> trash >> status >> trash >> experience >> trash
                    >> vehicleId;
                cin.ignore();

                Driver *driver = new Driver(id, age,
                                            MartialStatuesFactory::getMartialStatus(status),
                                            experience, vehicleId);
                so->addDriver(driver);
                break;
            }
            case 2: {
                cin >> id >> trash >> x_start >> trash >> y_start >> trash >> x_end >> trash
                    >> y_end >> trash >> num_passengers >> trash >> tariff;
                cin.ignore();
                Point *start = new Point(x_start, y_start);
                Point *end = new Point(x_end, y_end);
                TripInfo *tripInfo = new TripInfo(id, start, end, num_passengers, NULL, tariff);
                so->addTI(tripInfo);
                break;
            }

                //************************* לדאוג שמישהו יהיה אחראי לשנות את התעריף ***************

            case 3: {
                cin >> id >> trash >> taxi_type >> trash >> manufacturer >> trash >> color;
                cin.ignore();
                Taxi *taxi;
                if (taxi_type == 1) {
                    taxi = new Cab(ColorFactory::charToColor(color),
                                   CarManufactureFactory::charToFirm(manufacturer), id);
                } else if (taxi_type == 2) {
                    taxi = new LuxuryCab(ColorFactory::charToColor(color),
                                         CarManufactureFactory::charToFirm(
                                                 manufacturer), id);
                }
                so->addTaxi(taxi);
                break;
            }
            case 4: {
                cin >> id;
                cin.ignore();

                Point *location = so->getDriverLocation(id);

                cout << *location;
                break;
            }
            case 6: {
                so->moveAll();
                break;
            }
            default: {
                break;
            }
        }

    } while (choice != 7);

    //**************************לחזור למחוק הכל ****************


}

/*
3 3
0
3
0,1,H,G
1
0,30,M,1,0
2
0,0,0,0,2,1,20
6
4
0
6
4
0
6
 */

/*
1 - insert a driver in the following format:
        (id,age,status,experience,vehicleId) - (int,int,char:{S,M,D,W},int,int)
2 - insert a new ride:
        (id,x_start,y_start,x_end,y_end,num_passengers,tari ) - (int,int,int,int,int,int,double)
3 - insert a vehicle:
        (id,taxi_type,manufacturer,color) - (int,{1: Normal Cab,2: Luxury Cab},char:{H,S,T,F},char:{R,B,G,P,W})
4 - request for a driver location:
        (driver_id)
out: driver location in the format: '(x,y)'
• 6 - start driving (no input afterwards. Meaning getting all drivers to their end point)
• 7 - exit (cleaning up the program and exiting)
 */