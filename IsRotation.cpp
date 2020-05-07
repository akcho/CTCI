#include <iostream>
using namespace std;

bool IsSubstring(string s1, string s2);
bool IsRotation(string s1, string s2);

int main() {

}

bool IsRotation(string s1, string s2) {
    int len = s1.length();
    if (len == s2.length() && len > 0) {
        string s1s1 = s1 + s1;
        return IsSubstring(s1s1, s2);
    }
    return false;
}