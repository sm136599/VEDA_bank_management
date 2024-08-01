//
//  user.cpp
//  CPP
//
//  Created by 김서현 on 8/1/24.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

#include "user.h"
#include "account.h"
#include "deposit.h"
#include "saving.h"

User::User() : Person()
{
    
}

User::User(string name, int age) : Person(name, age)
{
    cout << "name: " << this->name << ", age: " << this->age << "인 사용자 생성\n";
}

void User::make_deposit()
{
    cout << "보통예금 - 입금할 액수를 입력하세요: \n";
    int money;
    cin >> money;
    this->accounts.push_back(new Deposit(money)); 
    cout << "보통예금이 생성되었습니다. \n";
    cout << "보통예금 잔액: " << money << '\n';
}

void User::make_saving()
{
    int money, year;
    cout << "정기예금 - 입금할 액수를 입력하세요: \n";
    cin >> money;
    cout << "정기예금 - 입금할 년 수를 입력하세요: \n";
    cin >> year;
    this->accounts.push_back(new Saving(money, year * 12));
    cout << "정기예금이 생성되었습니다.\n";
    cout << "정기예금 잔액: " << money << ", 기간: " << year << "년\n";
}

string User::who_is_this()
{
    return "User"; 
}

User::~User()
{
    cout << "name: " << this->name << ", age: " << this->age << "인 사용자 소멸\n";
}
