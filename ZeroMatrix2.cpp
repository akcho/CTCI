#include <iostream>
using namespace std;
#define M 4
#define N 4
int NUMBER_OF_ROWS = M - 1;
int NUMBER_OF_COLUMNS = N - 1;

void SetZeros(int matrix[M][N]);
void NullifyRow(int matrix[M][N], int row);
void NullifyColumn(int matrix[M][N], int column);

int main() {
}

void SetZeros(int matrix[M][N]) {
    bool row_has_zero = false;
    bool col_has_zero = false;

    for (int j = 0; j < NUMBER_OF_COLUMNS; j++) {
        if (matrix[0][j] == 0) {
            row_has_zero = true;
            break;
        }
    }

    for (int i = 0; i < NUMBER_OF_ROWS; i++) {
        if (matrix[i][0] == 0) {
            col_has_zero = true;
            break;
        }
    }

    for (int i = 1; i < NUMBER_OF_ROWS; i++) {
        for (int j = 1; j < NUMBER_OF_COLUMNS; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < NUMBER_OF_ROWS; i++) {
        if (matrix[i][0] == 0) {
            NullifyRow(matrix, i);
        }
    }

    for (int j = 1; j < NUMBER_OF_ROWS; j++) {
        if (matrix[0][j] == 0) {
            NullifyColumn(matrix, j);
        }
    }
}

void NullifyRow(int matrix[M][N], int row) {
    for (int i=0; i < NUMBER_OF_ROWS; i++) {
        matrix[row][i] = 0;
    }
}

void NullifyColumn(int matrix[M][N], int column) {
    for (int i=0; i < NUMBER_OF_COLUMNS; i++) {
        matrix[i][column] = 0;
    }
}