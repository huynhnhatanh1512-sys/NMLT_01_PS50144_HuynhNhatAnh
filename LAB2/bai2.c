#include <stdio.h>

int main() {
    float toan, ly, hoa, dtb;
    printf ("nhap diem toan: ");
    scanf("%f", &toan);
    
    printf ("nhap diem ly:");
    scanf("%f", &ly);
    
    printf ("nhap diem hoa:");
    scanf("%f", &hoa);
    
    dtb = (float)(toan * 3 + ly * 2 + hoa) / 6;

    printf("\ndiem trung binh: %.2f\n", dtb);
    return 0;
}