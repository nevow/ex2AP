//
// Created by nevo on 01/12/16.
//

#include "MainFlow.h"
#include "../enum/MartialStatuesFactory.h"
#include "../taxi/Cab.h"
#include "../enum/ColorFactory.h"
#include "../enum/CarManufatureFactory.h"
#include "../taxi/LuxuryCab.h"

using namespace std;

void MainFlow::input() {

    int rows, columns, id, age, experience, vehicleId, taxi_id, taxi_type;
    int id_ride, x_start, y_start, x_end, y_end, num_passengers;
    double tariff;
    char trash, status, manufacturer, color;

    cin >> rows >> trash >> columns;
    Map map(rows, columns);

    do {

        int choice;

        switch (choice) {

            case 1:
//********* להוסיף getCab
                cin >> id >> trash >> age >> trash >> status >> trash >> experience >> trash
                    >> vehicleId;

                Driver driver(id, age, MartialStatuesFactory::getMartialStatus(status), experience,
                              vehicleId);

                so.addDriver(&driver);

                break;

            case 2:
                cin >> id_ride >> trash >> x_start >> trash >> y_start >> trash >> x_end >> trash
                    >> y_end >> trash >> num_passengers >> trash >> tariff;

                Point start(x_start, y_start);
                Point end(x_end, y_end);

                TripInfo tripInfo(id_ride, &start, &end, num_passengers, NULL, tariff);

                so.addTI(&tripInfo);
                break;



                //************************* לדאוג שמישהו יהיה אחראי לשנות את התעריף ***************

            case 3:

                cin >> taxi_id >> trash >> taxi_type >> trash >> manufacturer >> trash >> color;
                if (taxi_type == 1) {
                    Cab taxi(ColorFactory::colorFromCharFactory(color),
                             CarManufatureFactory::carManufactureFromCharFactory(manufacturer), id);
                    so.addTaxi(&taxi);


                } else if (taxi_type == 2) {
                    LuxuryCab taxi(ColorFactory::colorFromCharFactory(color),
                                   CarManufatureFactory::carManufactureFromCharFactory(
                                           manufacturer), id);
                    so.addTaxi(&taxi);
                }
                break;


        }
    } while ();
}


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