//
//  user.h
//  CPP
//
//  Created by 김서현 on 8/1/24.
//

#ifndef user_h
#define user_h

#include "person.h"

class User : public Person {
    // vertor<Account*> accounts;
public:
    User();
    User(string, int);
    // 계좌 관련 함수들은 추후 추가 예정
    string who_is_this(); 
    ~User();
};

#endif /* user_h */
