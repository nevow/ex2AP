//
// Created by nevo on 01/12/16.
//

#include "MainFlow.h"
#include "../enum/MartialStatuesFactory.h"

using namespace std;

void MainFlow::input() {

    int rows, columns, id, age, experience, vehicle_id;
    char trash, status;
    cin >> rows >> trash >> columns;
    Map map(rows, columns);

    do {

        int choice;

        switch (choice) {

            case 1:
//********* להוסיף getCab
                cin >> id >> trash >> age >> trash >> status >> trash >> experience >> trash >> vehicle_id;

                Driver driver(id, age, MartialStatuesFactory::getMartialStatus(status), experience, vehicle_id);

                break;

            case 3:
//********* להוסיף getCab
                cin >> id >> trash >> age >> trash >> status >> trash >> experience >> trash >> vehicle_id;

                //*MainFlow::so

                break;


        }
    } while ();
}


/*

1 - insert a driver in the following format:
        (id,age,status,experience,vehicle_id) - (int,int,char:{S,M,D,W},int,int)


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