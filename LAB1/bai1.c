#include <stdio.h>
const float PI = 3.14159;

int main(){
    float dai, rong, r;
    printf("Nhap chieu dai: ");
    scanf("%f",&dai);
    printf("Nhap chieu rong: ");
    scanf("%f",&rong);


    printf("Chieu dai: %.2f\nChieu rong: %.2f\nChu vi HCN: %.2f\nDien tich HCN: %.2f\n",
        dai,rong,(dai + rong)*2,dai*rong);
    printf("Nhap ban kinh: ");
    scanf("%f",&r);
    printf("\nThong tin hinh tron:\nBan kinh: %.2f\nChu vi: %.2f\nDien tich: %.2f\n",r,r*2*PI,r*r*PI);

    return 0;
}