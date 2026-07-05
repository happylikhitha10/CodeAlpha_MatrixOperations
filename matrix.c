#include <stdio.h>

#define ROWS 2
#define COLS 2

void inputMatrix(int mat[ROWS][COLS], const char *name) {
    printf("Enter elements for matrix %s (%dx%d):\n", name, ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            scanf("%d", &mat[i][j]);
}

void printMatrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

void addMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

void transposeMatrix(int mat[ROWS][COLS], int result[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            result[j][i] = mat[i][j];
}

int main() {
    int a[ROWS][COLS], b[ROWS][COLS], sum[ROWS][COLS], product[ROWS][COLS], transposedA[COLS][ROWS];
    int choice;

    inputMatrix(a, "A");
    inputMatrix(b, "B");

    printf("\nMenu:\n1. Add Matrices\n2. Multiply Matrices\n3. Transpose Matrix A\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addMatrices(a, b, sum);
            printf("\nSum of Matrices:\n");
            printMatrix(sum);
            break;
        case 2:
            multiplyMatrices(a, b, product);
            printf("\nProduct of Matrices:\n");
            printMatrix(product);
            break;
        case 3:
            transposeMatrix(a, transposedA);
            printf("\nTranspose of Matrix A:\n");
            for (int i = 0; i < COLS; i++) {
                for (int j = 0; j < ROWS; j++)
                    printf("%d\t", transposedA[i][j]);
                printf("\n");
            }
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}