#include <stdio.h>
#include <windows.h>
#include <math.h>

#define MAX 100 // Đặt giới hạn kích thước tối đa cho mảng 1 chiều là 100 phần tử

float tinhTrungBinhCong(int a[], int n) {
    int tong = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 3 == 0 && a[i] % 5 == 0) {
            tong += a[i];
            count++;
        }
    }
    // Nếu không tìm thấy số nào thỏa mãn, trả về -1 để báo hiệu
    if (count == 0) return -1;
    return (float)tong / count;
}

void timMaxMin(int a[], int n, int *max, int *min) {
    *max = a[0];
    *min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > *max) *max = a[i];
        if (a[i] < *min) *min = a[i];
    }
}

void sapXepGiamDan(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void maTranBinhPhuong(int row, int col) {
    int a[row][col]; // Khai báo mảng 2 chiều với kích thước động (VLA)

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Nhập a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMa trận bình phương:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d", a[i][j] * a[i][j]); // In ra bình phương mỗi phần tử
        }
        printf("\n");
    }
}


void xuatSoLeMaTran(int row, int col) {
    int a[row][col];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Nhập a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nCác phần tử lẻ:\n");
    int found = 0; // Biến cờ để kiểm tra xem có số lẻ nào không
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (a[i][j] % 2 != 0) { // Kiểm tra số lẻ
                printf("a[%d][%d] = %d\n", i, j, a[i][j]);
                found = 1; // Đánh dấu là đã tìm thấy ít nhất một số lẻ
            }
        }
    }
    // Nếu duyệt hết ma trận mà không thấy số lẻ nào
    if (!found) {
        printf("Không có phần tử lẻ nào trong ma trận!\n");
    }
}

int main() {
    // Thiết lập hiển thị tiếng Việt có dấu cho cửa sổ console trên Windows
    SetConsoleOutputCP(65001);

    int luachon;
    int a[MAX], n;
    int row, col;

    do {
        // Hiển thị Menu chương trình
        printf("\n+-----------------------------------------------------------+\n");
        printf("|                    MENU CHƯƠNG TRÌNH LAB 6                |\n");
        printf("+-----------------------------------------------------------+\n");
        printf("| 1. Tính trung bình cộng các số chia hết cho 3 và 5        |\n");
        printf("| 2. Tìm giá trị lớn nhất và nhỏ nhất trong mảng            |\n");
        printf("| 3. Sắp xếp mảng theo thứ tự giảm dần                      |\n");
        printf("| 4. Ma trận bình phương (Mảng 2 chiều)                     |\n");
        printf("| 5. Lọc và xuất vị trí các số lẻ trong ma trận             |\n");
        printf("| 6. Thoát chương trình                                     |\n");
        printf("+-----------------------------------------------------------+\n");

        printf("Xin mời chọn chức năng (1-6): ");

        // Kiểm tra lỗi nếu người dùng nhập chữ cái thay vì số
        if (scanf("%d", &luachon) != 1) {
            printf("\n[Lỗi] Bạn phải nhập một số! Vui lòng thử lại.\n");
            while (getchar() != '\n'); // Xóa bộ nhớ đệm để tránh lặp vô hạn
            continue;
        }

        switch (luachon) {
        case 1: {
            printf("\n--- CHỨC NĂNG 1: TÍNH TRUNG BÌNH CỘNG CÁC SỐ CHIA HẾT CHO 3 VÀ 5 ---\n");
            
            // [LƯU Ý QUAN TRỌNG]: Phải ép n > 0 và n <= MAX để tránh tràn bộ nhớ
            do {
                printf("Nhập số lượng phần tử n (1 - %d): ", MAX);
                scanf("%d", &n);
                if (n <= 0 || n > MAX) {
                    printf("[Lỗi] Số lượng phần tử phải từ 1 đến %d! Nhập lại.\n", MAX);
                }
            } while (n <= 0 || n > MAX);

            for (int i = 0; i < n; i++) {
                printf("a[%d] = ", i);
                scanf("%d", &a[i]);
            }

            float tbc = tinhTrungBinhCong(a, n);

            if (tbc == -1)
                printf("Không tìm thấy số nào chia hết cho cả 3 và 5!\n");
            else
                printf("Trung bình cộng các số chia hết cho 3 và 5: %.2f\n", tbc);

            break;
        }

        case 2: {
            printf("\n--- CHỨC NĂNG 2: TÌM GIÁ TRỊ LỚN NHẤT VÀ NHỎ NHẤT ---\n");
            
            // Kiểm tra an toàn cho n
            do {
                printf("Nhập số lượng phần tử n (1 - %d): ", MAX);
                scanf("%d", &n);
                if (n <= 0 || n > MAX) {
                    printf("[Lỗi] Số lượng phần tử phải từ 1 đến %d! Nhập lại.\n", MAX);
                }
            } while (n <= 0 || n > MAX);

            for (int i = 0; i < n; i++) {
                printf("a[%d] = ", i);
                scanf("%d", &a[i]);
            }

            int max, min;
            timMaxMin(a, n, &max, &min);

            printf("Giá trị lớn nhất (Max): %d\n", max);
            printf("Giá trị nhỏ nhất (Min): %d\n", min);

            break;
        }

        case 3: {
            printf("\n--- CHỨC NĂNG 3: SẮP XẾP MẢNG GIẢM DẦN ---\n");
            
            // Kiểm tra an toàn cho n
            do {
                printf("Nhập số lượng phần tử n (1 - %d): ", MAX);
                scanf("%d", &n);
                if (n <= 0 || n > MAX) {
                    printf("[Lỗi] Số lượng phần tử phải từ 1 đến %d! Nhập lại.\n", MAX);
                }
            } while (n <= 0 || n > MAX);

            for (int i = 0; i < n; i++) {
                printf("a[%d] = ", i);
                scanf("%d", &a[i]);
            }

            sapXepGiamDan(a, n);

            printf("\nMảng sau khi sắp xếp giảm dần:\n");
            for (int i = 0; i < n; i++) {
                printf("a[%d] = %d\n", i, a[i]);
            }

            break;
        }

        case 4: {
            printf("\n--- CHỨC NĂNG 4: MA TRẬN BÌNH PHƯƠNG ---\n");
            
            // [LƯU Ý QUAN TRỌNG]: Kiểm tra row và col bắt buộc phải > 0 để không bị lỗi ma trận rỗng
            do {
                printf("Nhập số hàng (>0): ");
                scanf("%d", &row);
                printf("Nhập số cột (>0): ");
                scanf("%d", &col);
                if (row <= 0 || col <= 0) {
                    printf("[Lỗi] Số hàng và số cột phải lớn hơn 0! Nhập lại.\n");
                }
            } while (row <= 0 || col <= 0);

            maTranBinhPhuong(row, col);

            break;
        }

        case 5: {
            printf("\n--- CHỨC NĂNG 5: LỌC VÀ XUẤT VỊ TRÍ CÁC SỐ LẺ TRONG MA TRẬN ---\n");
            
            // Kiểm tra row và col phải > 0
            do {
                printf("Nhập số hàng (>0): ");
                scanf("%d", &row);
                printf("Nhập số cột (>0): ");
                scanf("%d", &col);
                if (row <= 0 || col <= 0) {
                    printf("[Lỗi] Số hàng và số cột phải lớn hơn 0! Nhập lại.\n");
                }
            } while (row <= 0 || col <= 0);

            xuatSoLeMaTran(row, col);

            break;
        }

        case 6:
            printf("\n---> Đang thoát chương trình... Tạm biệt!\n");
            break;

        default:
            printf("\n[Lỗi] Lựa chọn không hợp lệ! Vui lòng chọn từ 1 đến 6.\n");
            break;
        }

    } while (luachon != 6); // Lặp lại menu cho đến khi người dùng chọn 6

    return 0;
}