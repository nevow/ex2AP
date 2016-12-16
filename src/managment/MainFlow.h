//
// Created by nevo on 01/12/16.
//

#ifndef EX1_MAINFLOW_H
#define EX1_MAINFLOW_H

#include <list>

#include "SystemOperations.h"

class MainFlow {
private:
    SystemOperations *so;

public:
    MainFlow();

    ~MainFlow() {
        delete (so);
    }

    void initialize();

    void input();
};


#endif //EX1_MAINFLOW_H
