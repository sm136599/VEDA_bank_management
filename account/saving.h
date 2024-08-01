#pragma once

#include "account.h"
class Saving : public Account {
    int startDate;
    int duration;
public:
    Saving();
    Saving(int, int);
    void show_info();
    bool deposit(int money);
    bool isExpired();
};