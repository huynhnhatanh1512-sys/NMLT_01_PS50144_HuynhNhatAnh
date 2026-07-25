#include <stdio.h>
#include <math.h>

int main() {
    float a,b,x;
    printf("nhap a: ");
    scanf("%f", &a);
    printf("nhap b: ");
    scanf("%f", &b);
    x = -b / a;
    printf("nghiem x = %.2f\n", x);
    return 0;
}