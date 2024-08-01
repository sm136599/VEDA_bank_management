#pragma once

#include "account.h"
class Deposit : public Account {
public:
    Deposit();
    Deposit(int);
    void show_info();
    bool deposit(int money);
    bool withdraw(int money);
};