#ifndef account_h
#define account_h

class Account {
protected:
    time_t startDate;
    int account_number;
    int balance;
    int interest;
public:
    Account();
    Account(int);
    virtual void show_info();
    virtual void calculate_interest() = 0;
    bool deposit(int money);
    bool withdraw(int money);
    virtual ~Account();
};

#endif