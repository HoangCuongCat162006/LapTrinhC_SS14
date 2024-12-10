#include <stdio.h>

void inputArray(int arr[], int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n) {
    printf("Gia tri cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *n, int value, int position) {
    if (position < 0 || position > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*n)++;
    printf("Them thanh cong!\n");
}

void modifyElement(int arr[], int n, int value, int position) {
    if (position < 0 || position >= n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    arr[position] = value;
    printf("Sua thanh cong!\n");
}

void deleteElement(int arr[], int *n, int position) {
    if (position < 0 || position >= *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Xoa thanh cong!\n");
}

void sortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void linearSearch(int arr[], int n, int value) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Tim thay %d o vi tri %d\n", value, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay %d trong mang!\n", value);
    }
}

void binarySearch(int arr[], int n, int value) {
    sortAscending(arr, n); // Ð?m b?o m?ng du?c s?p x?p
    int left = 0, right = n - 1, found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            printf("Tim thay %d o vi tri %d\n", value, mid);
            found = 1;
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("Khong tim thay %d trong mang!\n", value);
    }
}

int main() {
    int arr[100], n = 0, choice, subChoice, value, position;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &n);
                break;

            case 2:
                printArray(arr, n);
                break;

            case 3:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can them: ");
                scanf("%d", &position);
                insertElement(arr, &n, value, position);
                break;

            case 4:
                printf("Nhap gia tri moi: ");
                scanf("%d", &value);
                printf("Nhap vi tri can sua: ");
                scanf("%d", &position);
                modifyElement(arr, n, value, position);
                break;

            case 5:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &position);
                deleteElement(arr, &n, position);
                break;

            case 6:
                printf("\nMENU SAP XEP\n");
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Lua chon: ");
                scanf(" %c", &subChoice);
                if (subChoice == 'a') {
                    sortDescending(arr, n);
                    printf("Sap xep giam dan thanh cong!\n");
                } else if (subChoice == 'b') {
                    sortAscending(arr, n);
                    printf("Sap xep tang dan thanh cong!\n");
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                break;

            case 7:
                printf("\nMENU TIM KIEM\n");
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                printf("Lua chon: ");
                scanf(" %c", &subChoice);
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                if (subChoice == 'a') {
                    linearSearch(arr, n, value);
                } else if (subChoice == 'b') {
                    binarySearch(arr, n, value);
                } else {
                    printf("Lua chon khong hop le!\n");
                }
                break;

            case 8:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}

