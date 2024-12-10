#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, m;
    printf("Nhap so hang: ");
    scanf("%d", &n);
    printf("Nhap so cot: ");
    scanf("%d", &m);

    int matrix[n][m];
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Nhap gia tri cac phan tu cua mang:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("Phan tu [%d][%d]: ", i, j);
                        scanf("%d", &matrix[i][j]);
                    }
                }
                break;

            case 2:
                printf("Ma tran:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%d ", matrix[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("Cac phan tu o goc:\n");
                printf("%d %d\n", matrix[0][0], matrix[0][m-1]);
                printf("%d %d\n", matrix[n-1][0], matrix[n-1][m-1]);
                break;

            case 4:
                printf("Cac phan tu tren duong bien:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                            printf("%d ", matrix[i][j]);
                        } else {
                            printf("0 ");
                        }
                    }
                    printf("\n");
                }
                break;

            case 5:
                printf("Cac phan tu tren duong cheo chinh va cheo phu:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (i == j || i + j == n - 1) {
                            printf("%d ", matrix[i][j]);
                        } else {
                            printf("0 ");
                        }
                    }
                    printf("\n");
                }
                break;

            case 6:
                printf("Cac phan tu la so nguyen to:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (isPrime(matrix[i][j])) {
                            printf("%d ", matrix[i][j]);
                        } else {
                            printf("0 ");
                        }
                    }
                    printf("\n");
                }
                break;

            case 7:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 7);

    return 0;
}

