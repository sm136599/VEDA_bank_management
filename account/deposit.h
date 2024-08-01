#ifndef deposit_h
#define deposit_h


#include "account.h"
class Deposit : public Account {
public:
    Deposit();
    Deposit(int);
    virtual void show_info();
    virtual void calculate_interest();
    bool deposit(int money);
    bool withdraw(int money);
};

#endif