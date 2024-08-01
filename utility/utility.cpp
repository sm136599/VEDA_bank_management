#include <iostream>
#include <string>

using namespace std;

string num_to_string_with_comma(int num) {
    string ret = "";
    int cnt = 0;
    while (num) {
        if (cnt == 3) {
            cnt = 0;
            ret = "," + ret;
        }
        ret = (char)((num % 10) + '0') + ret;
        cnt++;
        num /= 10;
    }
    return ret;
}