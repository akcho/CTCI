#include <iostream>
using namespace std;
int CHARS = 26;

int GetCharNumber(char c) {
    int a = 'a';
    int z = 'z';
    int val = c;
    if (a <= val && val <= z) {
        return val - a;
    }
    return -1;
}

bool IsPermutationOfPalindrome(string phrase) {
    int count_odd = 0;
    int table[26] = {0};
    for (int i = 0; i < phrase.length(); i++) {
        int x = GetCharNumber(phrase[i]);
        if (x != -1) {
            table[x]++;
            if (table[x] % 2 == 1) {
                count_odd++;
            } else {
                count_odd--;
            }
        }
    }
    return count_odd <= 1;
}

int main() {
    string phrase = "aabaa";
    cout << IsPermutationOfPalindrome(phrase);

    return 0;
}
