//
// Created by nevo on 01/12/16.
//

#ifndef EX1_SATISFACTION_H
#define EX1_SATISFACTION_H


class Satisfaction {
private:
    int amount;
    double average;
public:
    Satisfaction();

    double getAverage() const;

    void update(int grade);
};


#endif //EX1_SATISFACTION_H
