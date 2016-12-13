//
// Driver.
//

#include "Driver.h"

/**
 *
 * @param id of the driver
 * @param age of the driver
 * @param status of the driver
 * @param experience of the driver
 */
Driver::Driver(int id, int age, const MartialStatues &status, int experience) : id(id), age(age), status(status),
                                                                                experience(experience) {
    satisfaction = new Satisfaction();
}

/**
 *
 * @return the id of the driver
 */
int Driver::getId() const {
    return id;
}

/**
 *
 * @return the age of the driver
 */
int Driver::getAge() const {
    return age;
}

/**
 *
 * @param age of the driver to set
 */
void Driver::setAge(int age) {
    Driver::age = age;
}

/**
 *
 * @return the martial status of the driver
 */
const MartialStatues &Driver::getStatus() const {
    return status;
}

/**
 *
 * @param status of the driver to set.
 */
void Driver::setStatus(const MartialStatues &status) {
    Driver::status = status;
}

/**
 *
 * @return the experience of the driver
 */
int Driver::getExperience() const {
    return experience;
}

/**
 *
 * @param experience of the driveer to set.
 */
void Driver::setExperience(int experience) {
    Driver::experience = experience;
}

/**
 *
 * @return the trip info of the driver
 */
TripInfo *Driver::getTi() const {
    return ti;
}

/**
 *
 * @param ti of the driver to set.
 */
void Driver::setTi(TripInfo *ti) {
    Driver::ti = ti;
}

/**
 *
 * @return the satisfaction of the driver
 */
Satisfaction *Driver::getSatisfaction() const {
    return satisfaction;
}

/**
 *
 * @return the cab of the driver
 */
Taxi *Driver::getCab() const {
    return cab;
}

/**
 *
 * @param cab of the driver to set.
 */
void Driver::setCab(Taxi *cab) {
    Driver::cab = cab;
}

/**
 * make the driver move one step towards his destination.
 */
void Driver::moveOneStep() {
    cab->move(ti->getRoad());
}

/**
 *
 * @param grade to add for the driver satisfaction
 */
void Driver::updateSatisfaction(int grade) {
    satisfaction->update(grade);
}

/**
 *
 * @param otherDriver to compare id with this driver
 * @return true if the drivers have the same id
 */
bool Driver::operator==(const Driver &otherDriver) const {
    return id == otherDriver.id;
}

/**
 *
 * @param otherDriver to compare id with this driver
 * @return false if the drivers are equal
 */
bool Driver::operator!=(const Driver &otherDriver) const {
    return !(otherDriver == *this);
}