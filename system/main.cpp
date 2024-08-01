#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "person.h"
#include "user.h"
#include "manager.h"

map<string, pair<string, Person*>> sys; // id: <pw,person>
string id, pw;

void init_data()
{
    cout << "... 초기 데이터 입력중 ... \n";
    sys.insert(make_pair("seohyun", make_pair("010204", new User("seohyun", 24))));
    sys.insert(make_pair("sungmin", make_pair("990819", new User("sungmin", 26))));
    sys.insert(make_pair("manager", make_pair("000000", new Manager("매니저", 0))));
    cout << "\n\n";
}

void manager_mode()
{
    cout << "\n\n... 매니저 모드에 진입했습니다 ...\n\n";
}

void user_mode()
{
    cout << "\n\n... 유저 모드에 진입했습니다 ...\n\n";
    
    // 적금 깨기
}

void login()
{
    cout << "<< VEDA 은행 로그인 >>\n\n";
    while (true) {
        cout << "아이디를 입력하세요: ";
        cin >> id;
        cout << "비밀번호를 입력하세요: ";
        cin >> pw;
        
        if ((sys.find(id) == sys.end()) || (sys[id].first != pw))
            cout << "일치하는 정보가 없습니다. 다시 입력하세요.\n";
        
        if (sys[id].first == pw) {
            if (sys[id].second->who_is_this() == "Manager") {
                manager_mode();
                return;
            }
            else {
                user_mode();
                return;
            }
        }
    }
}

void description(void)
{
    cout << "\n\nVEDA 은행에는 다음과 같은 상품이 있습니다.\n";
    cout << "1. 예금: 2,147,483,648 원 한도, 연 3%(단리)\n";
    cout << "2. 희망적금: 1년간 월 최대 100만원 입금, 연 5%(단리)\n";
    cout << "3. 도약적금: 5년간 월 최대 100만원 입금, 연 7%(단리)\n";
    cout << "회원가입시 (1. 예금) 상품은 자동 개설됩니다.\n";
    cout << "많은 이용 바랍니다.\n\n\n";
}

void sign_up(void)
{
    cout << "<< VEDA 은행 회원 가입 >> \n\n";
    while (true) {
        cout << "사용할 아이디를 입력하세요: ";
        cin >> id;
        if (sys.find(id) != sys.end())
            cout << "중복되는 아이디가 있습니다.\n";
        else {
            cout << "사용할 비밀번호를 입력하세요: ";
            cin >> pw;
            string name;
            int age;
            cout << "이름을 입력하세요: ";
            cin >> name;
            cout << "나이를 입력하세요: ";
            cin >> age;
            sys.insert(make_pair(id, make_pair(pw, new User(name, age))));
            return;
        }
    }
}

void end_sys(void)
{
    cout << "\n<< VEDA 은행 시스템을 종료합니다. >> \n";
}

void init_screen()
{
    int cmd = 0;
    
    while (cmd != 1 && cmd != 9) {
//        system("cls");
        cout << "\n\n<< VEDA 은행에 오신 것을 환영합니다! >> \n";
        
        // 1: 로그인 ... login()
        cout << "1: 로그인\n";
        
        // 2: 회원가입 ... sign_up()
        cout << "2: 회원가입\n";
        
        // 3: 상품 조회 ... description()
        cout << "3: 상품 조회\n";
        
        // 9: 종료 ... end_sys()
        cout << "9: 종료\n";
        
        cout << "메뉴를 선택하세요: ";
        cin >> cmd;
        
        switch (cmd) {
            case 1: login(); return; break;
            case 2: sign_up(); break;
            case 3: description(); break;
            case 9: end_sys(); return;  break;
            default: cout << "다시 입력하세요.\n"; init_screen(); break;
        }
    }
}

int main(void)
{
    init_data();
    init_screen();
    
    return 0;
}
