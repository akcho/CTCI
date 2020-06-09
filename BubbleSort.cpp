#include <iostream>
#include <vector>
#include <string>
using namespace std;

void BubbleSort(string s) {
    bool is_swapped = true;

    while (is_swapped) {
        is_swapped = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i + 1] < s[i] && s[i+1] > 0) {
                char to_swap = s[i];
                s[i] = s[i+1];
                s[i + 1] = to_swap;
                is_swapped = true;
            }
        }
    }
    cout << s;
}


int main() {
    string s = "hello";

    BubbleSort(s);
    return 0;
}