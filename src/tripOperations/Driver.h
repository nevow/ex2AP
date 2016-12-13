//
// Created by nevo on 01/12/16.
//

#ifndef EX1_DRIVER_H
#define EX1_DRIVER_H


#include "../enum/MartialStatues.h"
#include "TripInfo.h"
#include "Satisfaction.h"
#include "../taxi/Taxi.h"

class Driver {
private:
    int id;
    int age;
    MartialStatues status;
    int experience;
    TripInfo *ti;
    Satisfaction *satisfaction;
    Taxi *cab;
public:
    Driver(int id, int age, const MartialStatues &status, int experience);

    int getId() const;

    int getAge() const;

    void setAge(int age);

    const MartialStatues &getStatus() const;

    void setStatus(const MartialStatues &status);

    int getExperience() const;

    void setExperience(int experience);

    TripInfo *getTi() const;

    void setTi(TripInfo *ti);

    Satisfaction *getSatisfaction() const;

    void updateSatisfaction(int grade);

    Taxi *getCab() const;

    void setCab(Taxi *cab);

    void moveOneStep();

    bool operator==(const Driver &otherDriver) const;

    bool operator!=(const Driver &otherDriver) const;
};


#endif //EX1_DRIVER_H
