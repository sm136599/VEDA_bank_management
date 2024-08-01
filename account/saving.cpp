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
}
void Saving::show_info() {
    cout << duration << "개월 적금 계좌" << endl;
    cout << "계좌 잔액: " << num_to_string_with_comma(balance) << "원" << endl;
}
bool Saving::deposit(int money) {
    Account::deposit(money);
    return true;
}
bool Saving::isExpired() {
    return (time(NULL) > startDate + duration);
}