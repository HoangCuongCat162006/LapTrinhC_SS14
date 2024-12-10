#include <stdio.h>

int main() {
    int rows, cols;

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Nhap gia tri cho ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Ma tran (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

