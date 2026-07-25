#include <stdio.h>

const float PI = 3.14159f; // sài const thay vì #define để khai báo và tránh lỗi khi biên dịch

int main() {
    float dai, rong, r;

    printf(" TINH CHU VI & DIEN TICH HCN \n");
    printf("Nhap chieu dai: ");
    scanf("%f", &dai);
    printf("Nhap chieu rong: ");
    scanf("%f", &rong);

    printf("\n[Thong tin HCN]\n");
    printf("Chieu dai: %.2f\n", dai);
    printf("Chieu rong: %.2f\n", rong);
    printf("Chu vi: %.2f\n", (dai + rong) * 2);
    printf("Dien tich: %.2f\n", dai * rong);

    printf("\n TINH CHU VI & DIEN TICH HINH TRON \n");
    printf("Nhap ban kinh: ");
    scanf("%f", &r);

    printf("\n[Thong tin Hinh Tron]\n");
    printf("Ban kinh: %.2f\n", r);
    printf("Chu vi: %.2f\n", 2 * r * PI);
    printf("Dien tich: %.2f\n", r * r * PI);

    return 0;
}