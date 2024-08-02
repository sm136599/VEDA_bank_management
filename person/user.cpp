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
    insert_deposit(money); 
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
    insert_saving(money, year * 12);
    cout << "정기예금이 생성되었습니다.\n";
    cout << "정기예금 잔액: " << money << ", 기간: " << year << "년\n";
}

void User::insert_deposit(int money, time_t s = time(NULL)) {
    this->accounts.push_back(new Deposit(money, s));
}

void User::insert_saving(int money, int duration, time_t s = time(NULL)) {
    this->accounts.push_back(new Saving(money, duration, s));
}

void User::show_all_account() {
    int idx = 0;
    for (const auto& account : accounts) {
        cout << idx << "번 계좌: "; 
        account->show_info();
    }
}

string User::who_is_this()
{
    return "User"; 
}

vector<Account*> User::get_accounts()
{
    return this->accounts; 
}

User::~User()
{
    for (const auto& account : accounts) {
        delete account;
    }
    cout << "name: " << this->name << ", age: " << this->age << "인 사용자 소멸\n";
}
