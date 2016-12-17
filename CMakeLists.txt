cmake_minimum_required(VERSION 3.6)
project(ex2AP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp test/coordinatesTests/MapTest.cpp test/coordinatesTests/NodeTest.cpp
        src/coordinates/Point.cpp src/coordinates/Point.h src/coordinates/Map.cpp
        src/coordinates/Map.h src/managment/BFS.cpp src/managment/BFS.h src/coordinates/Grid.h
        src/coordinates/CoordinatedItem.h src/coordinates/Node.cpp src/coordinates/Node.h
        src/main.cpp src/tripOperations/Driver.cpp src/tripOperations/Driver.h src/taxi/Taxi.h
        src/managment/SystemOperations.cpp src/managment/SystemOperations.h src/taxi/LuxuryCab.cpp
        src/taxi/LuxuryCab.h src/coordinates/Obstacle.cpp src/coordinates/Obstacle.h
        src/enum/MartialStatues.h src/enum/CarManufacture.h src/enum/Color.h
        src/tripOperations/Satisfaction.cpp src/tripOperations/Satisfaction.h
        src/listeners/TripEndListener.cpp src/listeners/TripEndListener.h
        src/listeners/EventListener.h src/tripOperations/TripInfo.cpp src/tripOperations/TripInfo.h
        src/tripOperations/TaxiCenter.cpp src/tripOperations/TaxiCenter.h src/managment/MainFlow.cpp
        src/managment/MainFlow.h src/tripOperations/Passenger.cpp src/tripOperations/Passenger.h
        src/taxi/Cab.cpp src/taxi/Cab.h test/coordinatesTests/PointTest.cpp
        test/listenersTest/TripEndListenerTest.cpp test/tripOperationsTests/DriverTest.cpp
        test/tripOperationsTests/PassengerTest.cpp test/tripOperationsTests/SatisfactionTest.cpp
        test/tripOperationsTests/TaxiCenterTest.cpp test/tripOperationsTests/TripInfoTest.cpp
        test/taxiTests/CabTest.cpp test/taxiTests/LuxuryCabTest.cpp
        test/managmentTests/SystemOperationsTest.cpp test/managmentTests/BFSTest.cpp
        src/enum/MartialStatuesFactory.h src/enum/ColorFactory.h src/enum/CarManufactureFactory.h
        test/managmentTests/MainFlowTest.cpp src/managment/ProperInput.cpp
        src/managment/ProperInput.h)
add_executable(ex2AP ${SOURCE_FILES} src/coordinates/Map.cpp src/coordinates/Map.h src/coordinates/Node.cpp src/coordinates/Node.h)

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)

include_directories(lib/googletest-master/googlemock/include)

target_link_libraries(ex2AP gtest gtest_main)
