#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define MAX 100
struct DienThoai
{
    char MaDienThoai[11],NhanHieu[21];
    int Gia;
};
struct DanhSachDienThoai
{
    DienThoai aDienThoai[MAX];
    int soluong=0;
};
bool KiemTraTonTai(DanhSachDienThoai ds,const char* MaDienThoai) 
{
    for (int i=0; i<ds.soluong; i++) 
    {
        if (strcmp(ds.aDienThoai[i].MaDienThoai,MaDienThoai)==0) 
        {
            return true; 
        }
    }
    return false;
}
void ThemDienThoai (DanhSachDienThoai &ds)
{
    if (ds.soluong >= MAX) 
    {
    cout << "Danh sach da day, khong the them moi\n";
    }
    DienThoai dt;
    cout<<"Moi ban nhap thong tin dien thoai: \n";
    cout<<"Moi ban nhap ma dien thoai: \n";
    cin>>dt.MaDienThoai;
    cout<<"Moi ban nhap nhan hieu dien thoai: \n";
    cin>>dt.NhanHieu;
    cout<<"Moi nhap gia dien thoai: \n";
    cin>>dt.Gia;
    if (KiemTraTonTai(ds,dt.MaDienThoai))
    {
        cout<<"Dien thoai da ton tai\n";
    }
    ds.aDienThoai[ds.soluong++]=dt;
    cout<<"Them dien thoai thanh cong\n";
}
void InDienThoai(const DanhSachDienThoai &ds)
{
    char MaDienThoai[11];
    cout<<"Moi nhap ma dien thoai: \n";
    cin>>MaDienThoai;
    for (int i=0;i<ds.soluong;i++)
    {
        if (strcmp(ds.aDienThoai[i].MaDienThoai, MaDienThoai) == 0)
        {
            cout<<"Nhan hieu cua ma dien thoai: "<<ds.aDienThoai[i].NhanHieu<<" \n";
            cout<<"Gia cua dien thoai: "<<ds.aDienThoai[i].Gia<<" \n";
        }
        else
        {
            cout<<"Ma dien thoai khong co trong danh sach\n";
        }
    }
}
void CapNhatGia (DanhSachDienThoai &ds)
{
    char MaDienThoai[11];
    cout<<"Moi nhap ma dien thoai: \n";
    cin>>MaDienThoai;
    for (int i=0;i<ds.soluong;i++)
    {
        if (strcmp(ds.aDienThoai[i].MaDienThoai, MaDienThoai) == 0)
        {
            cout<<"Cap nhat gia: \n";
            cin>>ds.aDienThoai[i].Gia;
        }
        else
        {
                cout<<"Ma dien thoai khong ton tai\n";
        }
    }
}
void XoaDienThoai (DanhSachDienThoai &ds)
{
char MaDienThoai[11];
    cout<<"Moi nhap ma dien thoai: \n";
    cin>>MaDienThoai;
    for (int i=0;i<ds.soluong;i++)
    {
        if (strcmp(ds.aDienThoai[i].MaDienThoai, MaDienThoai) == 0)
        {
            for (int j=i;j<ds.soluong-1;j++) 
            {
                ds.aDienThoai[j]=ds.aDienThoai[j+1];
            }
            ds.soluong--;
            cout<<"Xoa dien thoai thanh cong\n";
        }
        else  
        {  
            cout<<"Ma dien thoai khong ton tai\n";
        }
    }
}
void XuatDanhSach(DanhSachDienThoai &ds)
{
    if (ds.soluong==0) 
    {
        cout<<"Danh sach rong\n";
    }
    else
    {
    cout<<"Danh sach dien thoai:\n";
    for(int i = 0; i <ds.soluong; i++) 
    {
        cout<<"Ma dien thoai: "<<ds.aDienThoai[i].MaDienThoai<<" \n";
        cout<<"Nhan hieu: "<< ds.aDienThoai[i].NhanHieu<< " \n";
        cout<<"Gia: " <<ds.aDienThoai[i].Gia<<" \n";
    }
    }
}
void menu(DanhSachDienThoai ds)
{
    int LuaChon;
    do
    {
        cout<<"\n-----------Menu-----------\n";
        cout<<"1.Them dien thoai\n";
        cout<<"2.In dien thoai\n";
        cout<<"3.Cap nhat gia\n";
        cout<<"4.Xoa dien thoai\n";
        cout<<"5.Xuat danh sach\n";
        cout<<"0.Thoat\n";
        cin>>LuaChon;
        switch (LuaChon)
        {
            case 1:
                ThemDienThoai(ds);
                break;
            case 2:
                InDienThoai(ds);
                break;
            case 3:
                CapNhatGia(ds);
                break;
            case 4:
                XoaDienThoai(ds);
                break;
            case 5:
                XuatDanhSach(ds);
                break;
            case 0:
                cout<<"Thoat chuong trinh";
                break;
            default:
                cout<<"Khong hop le";
        }
    }
    while (LuaChon!=0);
}
int main()
{
    DanhSachDienThoai ds;
    menu(ds);
}