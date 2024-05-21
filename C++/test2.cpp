#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    int n;
    enum  gioitinh {Nu,Nam};
    struct ngaysinh
    {
        int ngay,thang,nam;
    }ns;
    struct canbo
    {
        int macanbo;
        char hoten[25];
        int tuoi;
        struct ngaysinh ngaysinh;
        enum gioitinh gioitinh;
    } cb;
    struct canbo danhsach[100];
    
    printf("Nhap so luong can bo can nhap thong tin: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {   
        printf("Nhap thong tin cua can bo thu %d\n", i+1);
        printf("Ma can bo: ");
        scanf("%d",&danhsach[i].macanbo);
        printf("Ho ten can bo: ");
        fflush(stdin);
        fgets(danhsach[i].hoten, sizeof(danhsach[i].hoten), stdin);
        printf("Nhap vao ngay sinh (nn tt nnnn): ");
        scanf("%d%d%d",&danhsach[i].ngaysinh.ngay,&danhsach[i].ngaysinh.thang,&danhsach[i].ngaysinh.nam);
        printf("Nhap vao gioi tinh(Nam/Nu). Nam nhap 1, nu nhap 0: ");
        scanf("%d",&danhsach[i].gioitinh);
        danhsach[i].tuoi=2023-danhsach[i].ngaysinh.nam;
    }
    system("cls");
    printf("Danh sach thong tin can bo:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Can bo thu %d:\n", i + 1);
        printf("Ma can bo: %d\n", danhsach[i].macanbo);
        printf("Ho ten: %s", danhsach[i].hoten);
        printf("Ngay sinh: %d/%d/%d\n", danhsach[i].ngaysinh.ngay, danhsach[i].ngaysinh.thang, danhsach[i].ngaysinh.nam);
        printf("Tuoi: %d\n",danhsach[i].tuoi);
		printf("Gioi tinh: %s\n", danhsach[i].gioitinh ? "Nam" : "Nu");
	}
    return 0;
}
