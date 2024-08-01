#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "headers.h"

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

void search_user()
{
    id = "";
    while (id != "exit") {
        cout << "\n\n조회할 유저의 id를 입력하세요(종료를 원할시 \"exit\" 입력): \n";
        cin >> id;
        if (id == "exit")
            break;
        if (sys.find(id) == sys.end())
            cout << "해당 id를 가진 유저가 없습니다.\n";
        else {
            cout << "*** " << id << " 유저의 정보 ***\n";
            cout << "유저의 이름: " << sys[id].second->get_name() << '\n';
            cout << "유저의 나이: " << sys[id].second->get_age() << '\n';
//            cout << "유저의 계좌: 총 " <<
        }
    }
    cout << "\n... 조회를 종료합니다 ...\n\n";
}

void manager_screen(void)
{
    int cmd = 0;
    
    while (cmd != 1 && cmd != 9) {
//        system("cls");
        cout << "\n\n... 매니저 모드에 진입했습니다 ...\n";
        
        // 1: 유저 조회 ... search_user()
        cout << "1: 유저 조회\n";
        
        // 2: 유저 삭제 ... delete_user()
        cout << "2: 유저 삭제\n";
        
        // 9: 매니저 모드 종료 ... init_screen()
        cout << "9: 매니저 모드 종료\n";
        
        cout << "메뉴를 선택하세요: ";
        cin >> cmd;
        
//        switch (cmd) {
//            case 1: search_user(); return; break;
//            case 2: delete_user(); break;
//            case 9: init_screen(); return;  break;
//            default: cout << "다시 입력하세요.\n"; init_screen(); break;
//        }
    }
}

// 유저 조회(내부에서 계좌 조회)/ 유저 삭제
void manager_mode()
{
    manager_screen();
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
    cout << "1. 보통예금: 10,000만원 한도, 연 3%(단리)\n";
    cout << "2. 정기예금: 1년 만기, 최대 5,000만원 입금, 연 5%(단리)\n";
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
