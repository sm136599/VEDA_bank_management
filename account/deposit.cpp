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
void Deposit::show_info() {
    cout << "계좌 종류: 보통 예금 계좌" << endl;
    cout << "계좌 생성일: " << make_time_string(startDate) << endl;
    cout << "계좌 잔액: " << num_to_string_with_comma(balance) << "원" << endl;
}
void Deposit::calculate_interest() {
    this->interest = balance * (0.03) / 12;
}
bool Deposit::deposit(int money) {
    Account::deposit(money);
    return true;
}
bool Deposit::withdraw(int money) {
    return Account::withdraw(money);
}