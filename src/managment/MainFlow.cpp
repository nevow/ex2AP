//
// MainFlow.
//

#include "MainFlow.h"

#include "../enum/MartialStatuesFactory.h"
#include "../taxi/Cab.h"
#include "../enum/ColorFactory.h"
#include "../enum/CarManufactureFactory.h"
#include "../taxi/LuxuryCab.h"

using namespace std;

/**
 * constructor.
 * initialize the environment, get map, obstacles and create a SystemOperations.
 */
MainFlow::MainFlow() {

    int rows, columns, obstacleNum;
    std::list<Node *> *obstacles = new list<Node *>;

    // get the map's size and create it
    cin >> rows >> columns;
    Map *map = new Map(columns, rows);
    cin.ignore();

    cin >> obstacleNum;
    cin.ignore();

    // make the obstacles List from the input
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
 * get inputs from user and follow the commands.
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
            // create new drive
            case 1: {
                cin >> id >> trash >> age >> trash >> status >> trash >> experience >> trash
                    >> vehicleId;
                cin.ignore();

                Driver *driver = new Driver(id, age,
                                            MartialStatuesFactory::getMartialStatus(status),
                                            experience, vehicleId);
                so->addDriver(driver);
                break;
            }
                // create new TripInfo
            case 2: {
                cin >> id >> trash >> x_start >> trash >> y_start >> trash >> x_end >> trash
                    >> y_end >> trash >> num_passengers >> trash >> tariff;
                cin.ignore();
                Point *start = new Point(x_start, y_start);
                Point *end = new Point(x_end, y_end);
                TripInfo *tripInfo = new TripInfo(id, start, end, num_passengers, tariff);
                so->addTI(tripInfo);
                break;
            }
                // create new Taxi
            case 3: {
                cin >> id >> trash >> taxi_type >> trash >> manufacturer >> trash >> color;
                cin.ignore();
                Taxi *taxi;

                if (taxi_type == 1)                      // create regular cab
                {
                    taxi = new Cab(ColorFactory::charToColor(color),
                                   CarManufactureFactory::charToFirm(manufacturer), id);

                } else if (taxi_type == 2)               // create LuxuryCab cab
                {
                    taxi = new LuxuryCab(ColorFactory::charToColor(color),
                                         CarManufactureFactory::charToFirm(
                                                 manufacturer), id);
                } else {
                    break;
                }
                so->addTaxi(taxi);
                break;
            }
                // request for a driver location by his id
            case 4: {
                cin >> id;
                cin.ignore();

                Point *location = so->getDriverLocation(id);

                cout << *location;
                break;
            }
                // start driving - getting all drivers to their end point
            case 6: {
                so->moveAll();
                break;
            }
                // every other case - don't do anything.
            default: {
                break;
            }
        }

    } while (choice != 7);     // exit condition
}
