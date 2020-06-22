#include <iostream>
#include <string>
using namespace std;

void Swap(char &c1, char &c2) {
    char temp = c2;
    c2 = c1;
    c1 = temp;
}

string SelectionSort(string s) {
    for (int i = 0; i < s.size(); i++) {
        char cached = 'z';
        int cached_index = 999;
        for (int j = i; j < s.size(); j++) {
            if (s[j] < cached) {
                cached = s[j];
                cached_index = j;
            }
        }
        s[cached_index] = s[i];
        s[i] = cached;
    }
    return s;
}


int main() {
    string s = "testing";
    string sorted = SelectionSort(s);

    cout << sorted;



    return 0;
}