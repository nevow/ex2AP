//
// TripInfo.
//

#include "TripInfo.h"
#include "../coordinates/Node.h"

/**
 *
 * @param location to check if it is the end of this trip.
 * @return true if the location is the end of the trip.
 */
bool TripInfo::checkEnd(Point *location) {
    return *location == *destination;
}

/**
 * constructor.
 *
 * @param rideId for the trip
 * @param start point of the trip
 * @param destination point of the trip
 * @param amountOfPassengers of the trip
 * @param passengers of the trip
 * @param tariff of the trip
 */
TripInfo::TripInfo(int rideId, Point *start, Point *destination, int amountOfPassengers,
                   list<Passenger *> *passengers, double tariff) :
        rideId(rideId), start(start), destination(destination),
        amountOfPassengers(amountOfPassengers), passengers(passengers), tariff(tariff) {
    currentDistance = 0;
    road = new stack<CoordinatedItem *>();
    road->push(new Node(destination));
}

/**
 *
 * @return the next point in the road
 */
stack<CoordinatedItem *> *TripInfo::getRoad() {
    return road;
}

/**
 *
 * @return the amount of passengers
 */
int TripInfo::getAmountOfPassengers() const {
    return amountOfPassengers;
}

/**
 *
 * @return the passengers in this trip
 */
list<Passenger *> *TripInfo::getPassengers() const {
    return passengers;
}


/**
 *
 * @return the starting point of this trip
 */
Point *TripInfo::getStart() const {
    return start;
}

/**
 *
 * @param ti is a trip info to compare if ti is equal
 * @return true if the ride ids match and the start and end points are the same
 */
bool TripInfo::operator==(const TripInfo &ti) const {
    return rideId == ti.rideId
           && *start == *ti.start
           && *destination == *ti.destination;
}

/**
 *
 * @param ti to compare with this trip info
 * @return true if the trips are not the same
 */
bool TripInfo::operator!=(const TripInfo &ti) const {
    return !(ti == *this);
}


