#include <iostream>
#include <string>
using namespace std;

bool OneAway(string first, string second);

int main() {
    cout << OneAway("pale", "ple");
}

bool OneAway(string first, string second) {
    if (abs(first.length() - second.length() > 1)) return false;
    string s1 = first.length() < second.length()? first: second;
    string s2 = first.length() < second.length()? second: first;
    int i1 = 0;
    int i2 = 0;
    bool found_difference = false;
    while (i1 < s1.length() && i2 < s2.length()) {
        if (s1[i1] != s2[i2]) {
            if (found_difference) return false;
            found_difference = true;
            if (s1.length() == s2.length()) i1++;   // for replace
        } else i1++;    // if matching, move shorter
        i2++;   // always increment longer string
    }
    return true;
}