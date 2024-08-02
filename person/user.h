#ifndef user_h
#define user_h

#include "person.h"
#include "../account/accountHeader.h"

class User : public Person {
     vector<Account*> accounts;
public:
    User();
    User(string, int);
    void deposit();
    void withdraw(); 
    virtual void show_all_account();
    virtual void make_saving(); 
    virtual void make_deposit();
    virtual string who_is_this();
    virtual ~User();
};

#endif /* user_h */
