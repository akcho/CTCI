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

int* BuildCharFrequencyTable(string phrase) {
    int table[26] = {0};
    for (int i = 0; i < phrase.length(); i++) {
        int x = GetCharNumber(phrase[i]);
        if (x != -1) {
            table[x]++;
        }
    }
    return table;
}

bool CheckMaxOneOdd(int* table) {
    bool found_odd = false;
    for (int i = 0; i < CHARS; i++) {
        if (table[i] %  2 == 1) {
            if (found_odd) {
                return false;
            }
            found_odd = true;
        }
    }
    return true;
}

bool IsPermutationOfPalindrome(string phrase) {
    int* table = BuildCharFrequencyTable(phrase);
    return CheckMaxOneOdd(table);
}

int main() {
    string phrase = "aabaa";
    cout << IsPermutationOfPalindrome(phrase);

    return 0;
}
