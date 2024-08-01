//
//  user.cpp
//  CPP
//
//  Created by 김서현 on 8/1/24.
//

#include <iostream>
#include <string>

using namespace std; 

#include "user.h"

User::User() : Person()
{
    
}

User::User(string name, int age) : Person(name, age)
{
    cout << "name: " << this->name << ", age: " << this->age << "인 사용자 생성\n";
}

// 계좌 관련 함수들은 추후 추가 예정

string User::who_is_this()
{
    return "User"; 
}

User::~User()
{
    cout << "name: " << this->name << ", age: " << this->age << "인 사용자 소멸\n";
}
