#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "deposit.h"

Deposit::Deposit() : Deposit(0) {

}
Deposit::Deposit(int money) : Account(money) {
    calculate_interest();
}
Deposit::~Deposit() {
    cout << "Deposit 소멸자" << endl;
}
void Deposit::show_info() {
    balance += interest * (time(NULL) - startDate);
    cout << "계좌 종류: 보통 예금 계좌" << endl;
    cout << "계좌 생성일: " << make_time_string(startDate) << endl;
    Account::show_info();
}
void Deposit::calculate_interest() {
    this->interest = balance * (0.03) / 12;
}
bool Deposit::deposit(int money) {
    return Account::deposit(money);
}
bool Deposit::withdraw(int money) {
    return Account::withdraw(money);
}