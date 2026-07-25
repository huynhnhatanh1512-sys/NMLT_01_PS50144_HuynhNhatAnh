#include <stdio.h>

int main() {
    char mssv[20];
    char ho[10], ten[10];
    float toan, ly, hoa, dtb;

    printf("Nhap MSSV: ");
    scanf("%s", mssv);

    printf("Nhap Ho va Ten: ");
    scanf("%s %s", ho, ten);

    printf("Nhap diem Toan, Ly, Hoa: ");
    scanf("%f %f %f", &toan, &ly, &hoa);

    dtb = (toan * 2 + ly + hoa) / 4;

    printf("\nMa so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s %s\n", ho, ten); 
    printf("Diem Trung Binh: %.2f\n", dtb);

    return 0;
}