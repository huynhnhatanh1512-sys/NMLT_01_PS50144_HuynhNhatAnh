#include <stdio.h>
#include <math.h>

void bai1_HocLuc() {
    float diem;
    printf("\nCHƯƠNG TRÌNH XẾP LOẠI HỌC LỰC\n");
    printf("Nhap tong so diem tu 0-10: ");
    scanf("%f", &diem);

    if (diem < 0 || diem > 10) {
        printf("Diem khong hop le: %.2f\n", diem);
    } else {
        if (diem >= 9) {
            printf("Xep loai xuat sac\n");
        } else if (diem >= 8) {
            printf("Xep loai gioi\n");
        } else if (diem >= 6.5) {
            printf("Xep loai kha\n");
        } else if (diem >= 5) {
            printf("Xep loai trung binh\n");
        } else if (diem >= 3.5) {
            printf("Xep loai yeu\n");
        } else {
            printf("Xep loai kem\n");
        }
    }
}

void bai2_PhuongTrinhBacHai() {
    float a, b, c, delta, x1, x2;
    printf("\nCHƯƠNG TRÌNH GIẢI PHƯƠNG TRÌNH BẬC 2\n");
    printf("Nhap he so a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Phuong trinh vo so nghiem\n");
            } else {
                printf("Phuong trinh vo nghiem\n");
            }
        } else {
            printf("Phuong trinh co 1 nghiem x = %.2f\n", -c / b);
        }
    } else {
        delta = b * b - 4 * a * c;
        if (delta < 0) {
            printf("Phuong trinh vo nghiem\n");
        } else if (delta == 0) {
            x1 = -b / (2 * a);
            printf("Phuong trinh co nghiem kep x1 = x2 = %.2f\n", x1);
        } else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Phuong trinh co 2 nghiem phan biet:\n");
            printf("x1 = %.2f\n", x1);
            printf("x2 = %.2f\n", x2);
        }
    }
}

void bai3_TienDien() {
    float kwh, tiendien;
    printf("\nCHƯƠNG TRÌNH TÍNH TIỀN ĐIỆN\n");
    printf("Nhap so kWh tieu thu: ");
    scanf("%f", &kwh);

    if (kwh < 0) {
        printf("So kWh phai la so duong!\n");
    } else {
        if (kwh <= 50) {
            tiendien = kwh * 1.678;
        } else if (kwh <= 100) {
            tiendien = 50 * 1.678 + (kwh - 50) * 1.734;
        } else if (kwh <= 200) {
            tiendien = 50 * 1.678 + 50 * 1.734 + (kwh - 100) * 2.014;
        } else if (kwh <= 300) {
            tiendien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + (kwh - 200) * 2.536;
        } else if (kwh <= 400) {
            tiendien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + (kwh - 300) * 2.834;
        } else {
            tiendien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + 100 * 2.834 + (kwh - 400) * 2.927;
        }

        printf("So tien dien phai tra la: %.2f VNĐ\n", tiendien);
    }
}

int main() {
    int chon;
    do {
        printf("\n+-----------------------------------+\n");
        printf("|    MENU CHƯƠNG TRÌNH LAB.         |\n");
        printf("+-----------------------------------+\n");
        printf("| 0. Thoat chuong trinh.            |\n");
        printf("| 1. Tinh hoc luc sinh vien.        |\n");
        printf("| 2. Giai phuong trinh bac 2.       |\n");
        printf("| 3. Tinh tien dien.                |\n");
        printf("+-----------------------------------+\n");
        printf("Ban hay chon chuc nang (0 - 3): ");
        scanf("%d", &chon);

        switch (chon) {
            case 0:
                printf("\nCam on ban da su dung chuong trinh. Tam biet!\n");
                break;
            case 1:
                bai1_HocLuc();
                break;
            case 2:
                bai2_PhuongTrinhBacHai();
                break;
            case 3:
                bai3_TienDien();
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon tu 0 den 3!\n");
                break;
        }
    } while (chon != 0);

    return 0;
}