//
// MainFlow.
//

#include "MainFlow.h"

#include "../enum/MartialStatuesFactory.h"
#include "../taxi/Cab.h"
#include "../enum/ColorFactory.h"
#include "../enum/CarManufactureFactory.h"
#include "../taxi/LuxuryCab.h"
#include "ProperInput.h"

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

    obstacleNum = ProperInput::validInt();

    // make the obstacles List from the input
    for (; obstacleNum > 0; obstacleNum--) {
        Point obs = ProperInput::validPoint(columns, rows);

        Node *n = new Node(&obs);
        obstacles->push_front(n);
    }

    so = new SystemOperations(map, obstacles);
}

/**
 * get inputs from user and follow the commands.
 */
void MainFlow::input() {
    int choice;
    int id, age, experience, vehicleId, taxi_type, num_passengers;
    double tariff;
    char trash, status, manufacturer, color;

    do {
        choice = ProperInput::validInt();
        cin.ignore();
        switch (choice) {
            // create new drive
            case 1: {
                id = ProperInput::validInt();
                age = ProperInput::validInt();
                cin >> status >> trash;
                experience = ProperInput::validInt();
                vehicleId = ProperInput::validInt();

                Driver *driver = new Driver(id, age,
                                            MartialStatuesFactory::getMartialStatus(status),
                                            experience, vehicleId);
                so->addDriver(driver);
                break;
            }
                // create new TripInfo
            case 2: {
                id = ProperInput::validInt();
                Point p1 = ProperInput::validPoint(so->getX(), so->getY());
                Point *start = new Point(p1.getX(), p1.getY());
                Point p2 = ProperInput::validPoint(so->getX(), so->getY());
                Point *end = new Point(p2.getX(), p2.getY());
                num_passengers = ProperInput::validInt();
                tariff = ProperInput::validInt();

                TripInfo *tripInfo = new TripInfo(id, start, end, num_passengers, tariff);
                so->addTI(tripInfo);
                break;
            }
                // create new Taxi
            case 3: {
                id = ProperInput::validInt();
                taxi_type = ProperInput::validInt();
                cin >> manufacturer >> trash >> color;
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
                id = ProperInput::validInt();
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

    } while (choice != 7);      // exit condition
}
