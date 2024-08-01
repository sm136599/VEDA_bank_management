#ifndef user_h
#define user_h

#include "person.h"
#include "../account/accountHeader.h"

class User : public Person {
     vector<Account*> accounts;
public:
    User();
    User(string, int);
    void make_deposit();
    void make_saving(); 
    void deposit();
    void withdraw(); 
    void show_all_account();
    string who_is_this();
    ~User();
};

#endif /* user_h */
