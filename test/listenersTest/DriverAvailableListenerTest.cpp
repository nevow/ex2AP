//
// check DriverAvailableListener.
//

#include <gtest/gtest.h>
#include "../../src/taxi/Cab.h"
#include "../../src/tripOperations/Driver.h"
#include "../../src/tripOperations/TaxiCenter.h"
#include "../../src/listeners/DriverAvailableListener.h"

/**
 * setup.
 */
class driverAvailableTest : public ::testing::Test {
protected:
    Driver *driver;
    TaxiCenter *taxiCenter;
    DriverAvailableListener *dal;
    TripInfo *tripInfo;
    Cab *cab;

    virtual void SetUp() {
        driver = new Driver(100, 40, MartialStatues::SINGLE, 10, 3);
        taxiCenter = new TaxiCenter();
        dal = new DriverAvailableListener(driver, taxiCenter);
        tripInfo = new TripInfo(10, new Point(0, 0), new Point(1, 1), 1, 2);
        cab = new Cab(Color::BLUE, CarManufacture::HONDA, 3);

        driver->setTi(tripInfo);
        driver->setCab(cab);
    }

    virtual void TearDown() {
        delete (driver);
        delete (taxiCenter);
        delete (dal);
        delete (tripInfo);
        delete (cab);
    }
};

/**
 * checks the notify method of the listener.
 * checks if set the driver as available, at the and of the driver ride.
 */
TEST_F(driverAvailableTest, notify) {
    std::list<Driver *> *drivers = taxiCenter->getAvailableDrivers();
    cab->applyToPoint(new Point(1, 1));

    dal->notify();

    Driver *driver1 = drivers->front();
    ASSERT_TRUE(*driver1 == *driver);
}