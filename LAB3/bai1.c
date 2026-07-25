#include <stdio.h>

int main() {
    float diem;
    printf("Nhap tong so diem tu 0-10: ");
    scanf("%f", &diem);

    if (diem < 0 || diem > 10) {
        printf("diem khong hop le: %.2f\n", diem);
    } else {
        if (diem >=9) {
            printf("xep loai xuat sac\n");
            } else if (diem >=8) {
              printf("xep loai gioi\n");
            } else if (diem >=6.5) {
                printf("xep loai kha\n");
            } else if (diem >=5) {
                printf("xep loai trung binh\n");
            } else if (diem >=3.5) {
                printf("xep loai yeu\n");
            } else {
                printf("xep loai kem\n");
            }
         }
        return 0;
    }