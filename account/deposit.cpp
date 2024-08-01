#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "deposit.h"

Deposit::Deposit() : Deposit(0) {

}
Deposit::Deposit(int money) : Account(money) {

}
void Deposit::show_info() {
    cout << "예금 계좌" << endl;
    cout << "계좌 잔액: " << num_to_string_with_comma(balance) << "원" << endl;
}
bool Deposit::deposit(int money) {
    Account::deposit(money);
    return true;
}
bool Deposit::withdraw(int money) {
    return Account::withdraw(money);
}