#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "account.h"

Account::Account() : Account(0) {}
Account::Account(int money) {
  this->balance = money;
  this->startDate = time(NULL);
}
Account::~Account() {
    cout << "Account 소멸자" << endl;
}
void Account::show_info() {
  cout << "계좌 잔액: " << num_to_string_with_comma(balance) << "원" << endl;
}
bool Account::deposit(int money) {
  this->balance += money;
  cout << num_to_string_with_comma(money) << "원 입금 완료" << endl;
  return true;
}
bool Account::withdraw(int money) {
  if (this->balance < money) {
    cout << "잔액 부족" << endl;
    return false;
  }
  this->balance -= money;
  cout << num_to_string_with_comma(money) << "원 출금 완료" << endl;
  return true;
  // try
  // {
  //   if (this->balance < money) throw new exception("잔액 부족");
  //   this->balance -= money;
  //   cout << money << "원 출금 완료" << endl;
  // }
  // catch(const std::exception& e)
  // {
  //   std::cerr << e.what() << '\n';
  // }
}