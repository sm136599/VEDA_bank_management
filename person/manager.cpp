//
//  manager.cpp
//  CPP
//
//  Created by 김서현 on 8/1/24.
//

#include <iostream>
#include <string>

using namespace std;

#include "manager.h"

Manager::Manager() : Person()
{
    
}

Manager::Manager(string name, int age) : Person(name, age)
{
    cout << "name: " << this->name << ", age: " << this->age << "인 관리자 생성\n";
}





Manager::~Manager()
{
    cout << "name: " << this->name << ", age: " << this->age << "인 관리자 소멸\n";
}