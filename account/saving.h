#ifndef saving_h
#define saving_h

#include "account.h"
class Saving : public Account {
    int duration;
public:
    Saving();
    Saving(int, int);
    virtual void show_info();
    virtual void calculate_interest();
    bool deposit(int money);
    bool isExpired();
    virtual ~Saving();
};

#endif