#pragma once

class Account {
protected:
    int account_number;
    int balance;
public:
    Account();
    Account(int);
    virtual void show_info();
    bool deposit(int money);
    bool withdraw(int money);
};