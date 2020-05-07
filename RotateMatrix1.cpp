#include <iostream>
using namespace std;
#define N 4

bool rotate(int matrix[N][N]) {
    for (int layer = 0; layer < N / 2; layer++) {
        int first = layer;
        int last = N - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top_left = matrix[first][i];     // save top left corner
            matrix[first][i] = matrix[last-offset][first];  // top_left = bottom_left
            matrix[last-offset][first] = matrix[last][last - offset];   //bottom_left = bottom_right
            matrix[last][last - offset] = matrix[i][last];  // bottom_right = top_right
            matrix[i][last] = top_left;  // top_right = original top_left
        }
    }
    return true;
}

int main() {
}



