#include <stdio.h>
#define MAX 100
struct NhanVien
{
    char MaSo[11],Ho[11],Ten[51];
    int Phai, ThamNien;
};
struct PhongBan
{
    NhanVien aNhanVien[MAX];
    int SoLuong;
};
void NhapPhongBan(PhongBan &pb)
{
    printf("Nhap so luong luong nhan vien: ");
    scanf("%d",&pb.SoLuong);
    while(pb.SoLuong<=0 || pb.SoLuong>MAX)
    {
        printf("Khong hop le, moi nhap lai: ");
        scanf("%d",&pb.SoLuong);
    }
    getchar();
    for(int i=0; i<pb.SoLuong; i++)
    {
        printf("Nhap thong tin nhan vien %d:\n",i+1);
        printf("+ Ma so: ");
        fgets(pb.aNhanVien[i].MaSo, sizeof(pb.aNhanVien[i].MaSo),stdin);
        printf("+ Ho: ");
        fgets(pb.aNhanVien[i].Ho, sizeof(pb.aNhanVien[i].Ho),stdin);
        printf("+ Ten: ");
        fgets(pb.aNhanVien[i].Ten, sizeof(pb.aNhanVien[i].Ten),stdin);
        printf("+ Phai: ");
        while (scanf("%d", &pb.aNhanVien[i].Phai) != 1 || (pb.aNhanVien[i].Phai != 0 && pb.aNhanVien[i].Phai != 1))
        {
            while(getchar() != '\n');
            printf("Khong hop le, moi nhap lai: ");
        }
        printf("+ So nam lam viec: ");
        scanf("%d",&pb.aNhanVien[i].ThamNien);
        while (pb.aNhanVien[i].ThamNien<0)
        {
            printf("Khong hop le, moi nhap lai: ");
            scanf("%d",&pb.aNhanVien[i].ThamNien);
        }
        getchar();
    }
}
void XuatPhongBan(PhongBan pb)
{
    printf("Phong ban co %d nhan vien\n",pb.SoLuong);
    printf("STT\tMa so\tHo\tTen\t\tPhai\tTham nien\n");
    for (int i=0;i<pb.SoLuong;i++)
    {
        printf("%d\t%-10s\t%-20s\t %-30s\t",i+1,pb.aNhanVien[i].MaSo,pb.aNhanVien[i].Ho,pb.aNhanVien[i].Ten);
        if (pb.aNhanVien[i].Phai==0)
        printf("Nu\t");
        else
        printf("Nam\t");
        printf("%-10d",pb.aNhanVien[i].ThamNien);
        printf("\n");
    }
}
void DemSiSo(PhongBan ds, int &sonam, int &sonu) 
{
    sonam=0;
    sonu=0;
    for (int i=0;i<ds.SoLuong;i++)
    {
    if (ds.aNhanVien[i].Phai==0)
    sonu++;
    else
    sonam++;
    }
    printf("Phong ban co %d nam\n",sonam);
    printf("Phong ban co %d nu\n",sonu);
}
void SapXepTangTheoThamNien(PhongBan &pb) 
{
    for (int i=0;i<pb.SoLuong-1;i++)
    {
    for (int j=i+1;j<pb.SoLuong;j++)
    {
        if (pb.aNhanVien[i].ThamNien>pb.aNhanVien[j].ThamNien)
        {
        NhanVien t =pb.aNhanVien[i];
        pb.aNhanVien[i]=pb.aNhanVien[j];
        pb.aNhanVien[j]= t;
        }
    }
    }
}
int main()
{
    PhongBan pb;
    int sonam,sonu;
    NhapPhongBan(pb);
    XuatPhongBan(pb);
    DemSiSo(pb,sonam,sonu);
    SapXepTangTheoThamNien(pb);
    printf("Phong ban sau khi xep theo tham nien\n");
    XuatPhongBan(pb);
}
