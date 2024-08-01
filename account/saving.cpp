#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

#include "saving.h"


Saving::Saving() : Saving(0, 0) {

}
Saving::Saving(int money, int duration) : Account(money), duration(duration) {
    this->startDate = time(NULL);
    calculate_interest();
}
void Saving::show_info() {
    balance += interest * (time(NULL) - startDate);
    cout << "계좌 종류: " << duration << "개월 정기 예금 계좌" << endl;
    cout << "계좌 생성일: " << make_time_string(startDate) << endl;
    Account::show_info();
}
void Saving::calculate_interest() {
    int year = duration / 12;
    this->interest = balance * (0.05) * year / 12;
}
bool Saving::deposit(int money) {
    Account::deposit(money);
    return true;
}
bool Saving::isExpired() {
    return (time(NULL) > startDate + duration);
}