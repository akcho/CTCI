#include <iostream>
using namespace std;
#define M 4
#define N 4
int ROW_LENGTH = M - 1;
int COLUMN_LENGTH = N - 1;

void SetZeros(int matrix[M][N]);
void NullifyRow(int matrix[M][N], int row);
void NullifyColumn(int matrix[M][N], int column);

int main() {
}

void SetZeros(int matrix[M][N]) {
    bool* row = new bool[ROW_LENGTH];
    bool* column = new bool[COLUMN_LENGTH];
    for (int i = 0; i < ROW_LENGTH; i++) {
        for (int j = 0; j < COLUMN_LENGTH; j++) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                column[j] = true;
            }
        }
    }
    for (int i = 0; i < ROW_LENGTH; i++) {
        if (row[i]) NullifyRow(matrix, i);
    }
    for (int j = 0; j < COLUMN_LENGTH; j++) {
        if (column[j]) NullifyColumn(matrix, j);
    }
}

void NullifyRow(int matrix[M][N], int row) {
    for (int i=0; i < ROW_LENGTH; i++) {
        matrix[row][i] = 0;
    }
}

void NullifyColumn(int matrix[M][N], int column) {
    for (int i=0; i < COLUMN_LENGTH; i++) {
        matrix[i][column] = 0;
    }
}