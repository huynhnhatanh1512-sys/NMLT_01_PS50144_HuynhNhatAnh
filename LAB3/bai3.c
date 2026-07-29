#include <stdio.h>

int main() {
    float kwh, tiendien;
    printf("nhap so kwh tieu thu: ");
    scanf("%f", &kwh);
    if (kwh < 0) {
        printf(" so kwh phai la so duong\n");
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
   return 0;
}
