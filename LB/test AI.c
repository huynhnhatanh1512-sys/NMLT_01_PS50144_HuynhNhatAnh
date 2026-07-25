#include <stdio.h>
#include <string.h>

#define MAX 50

struct SinhVien {
    int maSV;
    char ten[50];
    int coMat;
};

struct SinhVien ds[MAX];
int soLuong = 0;

// Thêm sinh viên
void themSinhVien() {
    printf("\nNhap ma sinh vien: ");
    scanf("%d", &ds[soLuong].maSV);

    printf("Nhap ten sinh vien: ");
    getchar();
    fgets(ds[soLuong].ten, sizeof(ds[soLuong].ten), stdin);
    ds[soLuong].ten[strcspn(ds[soLuong].ten, "\n")] = '\0';

    ds[soLuong].coMat = 0;
    soLuong++;

    printf("Them sinh vien thanh cong!\n");
}

// Hiển thị danh sách
void hienThiDanhSach() {
    printf("\n===== DANH SACH SINH VIEN =====\n");

    for (int i = 0; i < soLuong; i++) {
        printf("Ma: %d | Ten: %s | Trang thai: %s\n",
               ds[i].maSV,
               ds[i].ten,
               ds[i].coMat ? "Co mat" : "Vang");
    }
}

// Điểm danh
void diemDanh() {
    int ma;
    int timThay = 0;

    printf("\nNhap ma sinh vien can diem danh: ");
    scanf("%d", &ma);

    for (int i = 0; i < soLuong; i++) {
        if (ds[i].maSV == ma) {
            timThay = 1;

            printf("Sinh vien: %s\n", ds[i].ten);
            printf("1. Co mat\n");
            printf("0. Vang\n");
            printf("Chon: ");
            scanf("%d", &ds[i].coMat);

            printf("Da cap nhat diem danh!\n");
            break;
        }
    }

    if (!timThay)
        printf("Khong tim thay sinh vien!\n");
}

// Báo cáo
void baoCao() {
    int coMat = 0;
    int vang = 0;

    for (int i = 0; i < soLuong; i++) {
        if (ds[i].coMat)
            coMat++;
        else
            vang++;
    }

    printf("\n===== BAO CAO =====\n");
    printf("Tong sinh vien: %d\n", soLuong);
    printf("Co mat: %d\n", coMat);
    printf("Vang: %d\n", vang);
}

int main() {
    int luaChon;

    do {
        printf("\n========== QUAN LY DIEM DANH ==========\n");
        printf("1. Them sinh vien\n");
        printf("2. Xem danh sach\n");
        printf("3. Diem danh\n");
        printf("4. Bao cao\n");
        printf("0. Thoat\n");

        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                themSinhVien();
                break;
            case 2:
                hienThiDanhSach();
                break;
            case 3:
                diemDanh();
                break;
            case 4:
                baoCao();
                break;
            case 0:
                printf("Ket thuc chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (luaChon != 0);

    return 0;
}