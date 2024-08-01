//
//  manager.cpp
//  CPP
//
//  Created by 김서현 on 8/1/24.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "manager.h"

Manager::Manager() : Person()
{
    
}

Manager::Manager(string name, int age) : Person(name, age)
{
    cout << "name: " << this->name << ", age: " << this->age << "인 관리자 생성\n";
}


string Manager::who_is_this()
{
    return "Manager";
}

void Manager::make_deposit()
{
    return;
}

void Manager::make_saving()
{
    return;
}
void Manager::show_all_account() 
{
    return;
}

Manager::~Manager()
{
    cout << "name: " << this->name << ", age: " << this->age << "인 관리자 소멸\n";
}
