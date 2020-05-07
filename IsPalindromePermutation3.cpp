#include <iostream>
using namespace std;

int GetCharNumber(char c) {
    int a = 'a';
    int z = 'z';
    int val = c;
    if (a <= val && val <= z) {
        return val - a;
    }
    return -1;
}

int Toggle(int bit_vector, int index) {
    if (index < 0) return bit_vector;
    int mask = 1 << index;
    bit_vector ^= mask;
    return bit_vector;
}

int CreateBitVector(string phrase) {
    int bit_vector = 0;
    for (int i = 0; i < phrase.length(); i++) {
        int x = GetCharNumber(phrase[i]);
        bit_vector = Toggle(bit_vector, x);
    }
    return bit_vector;
}

bool CheckAtMostOneBitSet(int bit_vector) {
    return (bit_vector & (bit_vector - 1)) == 0;
}

bool IsPalPerm(string phrase) {
    int bit_vector = CreateBitVector(phrase);
    return CheckAtMostOneBitSet(bit_vector);
}

int main() {
    cout << IsPalPerm("ab");
    return 0;
}
