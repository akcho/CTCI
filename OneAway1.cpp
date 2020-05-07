#include <iostream>
#include <string>
using namespace std;

bool CheckForAdd(string str1, string str2, int index);
bool CheckForRemove(string str1, string str2, int index);
bool CheckForReplace(string str1, string str2, int index);
bool OneAway(string str1, string str2);

int main() {
    cout << OneAway("pale", "bake");
}

bool CheckForAdd(string str1, string str2, int index) {
    return str2.substr(index, str2.length())== str1.substr(index + 1, str1.length());
}

bool CheckForRemove(string str1, string str2, int index) {
    return str2.substr(index,str2.length()) == str1.substr(index, str1.length());
}

bool CheckForReplace(string str1, string str2, int index) {
    return str2.substr(index + 1, str2.length()) == str1.substr(index + 1, str1.length());
}

bool OneAway(string str1, string str2) {
    bool can_fix = false;
    for (int i = 0; i < str2.length(); i++) {
        if (str1[i] != str2[i]) {
            if (CheckForAdd(str1, str2, i)) can_fix = true;
            if (can_fix) return true;
            if (CheckForRemove(str1, str2, i)) can_fix = true;
            if (can_fix) return true;
            if (CheckForReplace(str1, str2, i)) can_fix = true;
            if (can_fix) return true;
            }
        }
    return str1.length() == str2.length() + 1;
    }