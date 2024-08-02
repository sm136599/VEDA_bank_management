#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

#include "headers.h"

map<string, pair<string, Person*>> sys; // id: <pw,person>
string id, pw;

void search_user()
{
    id = "";
    while (id != "exit") {
        cout << "\n\n조회할 유저의 id를 입력하세요(종료를 원할시 \"exit\" 입력): \n";
        cin >> id;
        if (id == "exit")
            break;
        
        const auto& found_user = sys.find(id);
        if (found_user == sys.end())
            cout << "해당 id를 가진 유저가 없습니다.\n";
        else {
            cout << "*** " << id << " 유저의 정보 ***\n";
            cout << "유저의 이름: " << found_user->second.second->get_name() << '\n';
            cout << "유저의 나이: " << found_user->second.second->get_age() << '\n';
            found_user->second.second->show_all_account();
        }
    }
    cout << "\n... 조회를 종료합니다 ...\n\n";
}

void delete_user() {
    id = "";
    while (id != "exit") {
        cout << "\n\n삭제할 유저의 id를 입력하세요(종료를 원할시 \"exit\" 입력): \n";
        cin >> id;
        if (id == "exit")
            break;
        
        const auto& found_user = sys.find(id);
        if (found_user == sys.end())
            cout << "해당 id를 가진 유저가 없습니다.\n";
        else {
            cout << "*** " << id << " 유저의 정보 ***\n";
            cout << "유저의 이름: " << found_user->second.second->get_name() << '\n';
            cout << "유저의 나이: " << found_user->second.second->get_age() << '\n';
            found_user->second.second->show_all_account();

            cout << "정말 삭제 하시겠습니까? (y/n) ";
            string ans; cin >> ans;
            if (ans == "y" || ans == "Y") {
                delete found_user->second.second;
                sys.erase(found_user);
                cout << "삭제를 완료하였습니다.\n";
            }

        }
    }
    cout << "\n... 삭제를 종료합니다 ...\n\n";
}

void manager_screen(void)
{
    int cmd = 0;
    
    while (cmd != 9) {
//        system("cls");
        cout << "\n\n... 매니저 모드에 진입했습니다 ...\n";
        
        // 1: 유저 조회 ... search_user()
        cout << "1: 유저 조회\n";
        
        // 2: 유저 삭제 ... delete_user()
        cout << "2: 유저 삭제\n";
        
        // 9: 매니저 모드 종료 ... init_screen()
        cout << "9: 로그 아웃\n";
        
        cout << "메뉴를 선택하세요: ";
        cin >> cmd;
        
       switch (cmd) {
           case 1: search_user(); break;
           case 2: delete_user(); break;
           case 9: break;
           default: cout << "다시 입력하세요.\n"; break;
       }
    }
}

// 유저 조회(내부에서 계좌 조회)/ 유저 삭제
void manager_mode()
{
    manager_screen();
}

void make_account()
{
    cout << "만드실 계좌를 선택해주세요\n";
    cout << "1. 보통예금: 10,000만원 한도, 연 3%(단리)\n";
    cout << "2. 정기예금: 1년 만기, 최대 5,000만원 입금, 연 5%(단리)\n";
    int cmd;
    cin >> cmd;
    if (cmd == 1)
        sys[id].second->make_deposit();
    else
        sys[id].second->make_saving();
    return;
}

void delete_account()
{
    cout << "삭제할 계좌를 선택해주세요\n";
    sys[id].second->show_all_account();
}

void user_mode()
{
//  전체 계좌 조회(계좌번호, 잔액, 계좌의 종류 출력) / 계좌 개설 / 계좌 삭제 / 탈퇴
    int cmd = 0;
    while (cmd != 9) {
    //    system("cls");
        cout << "\n\n... 유저 모드에 진입했습니다 ...\n\n";
        // 1: 전체 계좌 조회 ... show_all_account()
        cout << "1: 전체 계좌 조회\n";
        // 2: 계좌 개설 ... make_account()
        cout << "2: 계좌 개설\n";
        // 3: 계좌 삭제 ... delete_account()
        cout << "3: 계좌 삭제\n";
        // 4: 회원 탈퇴 ...
        cout << "4: 회원 탈퇴\n";
        // 9: 종료 ... end_sys()
        cout << "9: 로그 아웃\n";
        cout << "메뉴를 선택하세요: ";
        cin >> cmd;
        switch (cmd) {
        case 1: sys[id].second->show_all_account() ; break;
        case 2: make_account(); break;
          case 3: delete_account(); break;
        case 4: delete sys[id].second; sys.erase(id); cout << "탈퇴가 완료되었습니다.\n"; break;
    //      case 9: end_sys(); return; break;
        default: cout << "다시 입력하세요.\n"; break;
        }
    }
}
void login()
{
    cout << "<< VEDA 은행 로그인 >>\n\n";
    while (true) {
        cout << "뒤로가기 '-1' 입력\n";
        cout << "아이디를 입력하세요: ";
        cin >> id;
        if (id == "-1") break;
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
    
    while (cmd != 9) {
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
            case 1: login(); break;
            case 2: sign_up(); break;
            case 3: description(); break;
            case 9: end_sys(); return;  break;
            default: cout << "다시 입력하세요.\n"; init_screen(); break;
        }
    }
}

void init_data()
{
    cout << "... 초기 데이터 입력중 ... \n";
    ifstream fin;
    fin.open("person_data.txt");

    int N; fin >> N;
    for (int i = 0; i < N; i++) {
        string id, pw, person_type; fin >> person_type >> id >> pw;
        string name; int age; fin >> name >> age;
        
        if (person_type == "User") {
            sys.insert(make_pair(id, make_pair(pw, new User(name, age))));
            int account_N; fin >> account_N;
            Person* tmp = sys[id].second;
            for (int j = 0; j < account_N; j++) {
                string account_type; int s; int balance;
                fin >> account_type >> s >> balance;
                if (account_type == "Deposit") {
                    tmp->insert_deposit(balance, s);
                }
                else if (account_type == "Saving") {
                    int duration; fin >> duration;
                    tmp->insert_saving(balance, duration, s);
                }
            }
        }
        else if (person_type == "Manager") {
            sys.insert(make_pair(id, make_pair(pw, new Manager(name, age))));
        }
    }
    cout << "\n\n";
    fin.close();
}
void save_data() {
    ofstream fout;
    fout.open("person_data.txt");

    fout << sys.size() << endl;
    for (const auto& person : sys) {
        const string& type = person.second.second->who_is_this();
        fout << type << " " << person.first << " " << person.second.first << " " << endl;
        fout << person.second.second->get_name() << " " << person.second.second->get_age() << endl;
        if (type == "User") {
            const auto& accounts = person.second.second->get_accounts();
            fout << accounts.size() << endl;
            for (const auto& account : accounts) {
                const string& account_type = account->who_is_this();
                fout << account_type << " " << account->get_start_date() << " " << account->get_balance() << " ";
                if (account_type == "Saving") fout << account->get_duration() << endl;
                else fout << endl;
            }
        }

    }
    fout.close();
}

int main(void)
{
    init_data();
    init_screen();
    save_data();
    
    return 0;
}
