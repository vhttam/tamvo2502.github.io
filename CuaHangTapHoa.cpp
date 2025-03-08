#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define MAX 100
struct MatHang
{
    char MSMH[201],TenMH[201];
    int SoLuong,DonGia;
};
struct DanhSachMatHang
{
    MatHang aMatHang[MAX];
    int n;
};
void NhapMatHang(DanhSachMatHang &ds)
{
    cout<<"Moi ban nhap so luong mat hang: \n";
    cin>>ds.n;
    while (ds.n>MAX)
    {
        cout<<"Vuot qua so mat hang toi da, moi nhap lai: \n";
        cin>>ds.n;
    }
    for (int i=0;i<ds.n;i++)
    {
        cout<<"Moi ban nhap ten mat hang thu "<<i+1<<": \n";
        cin>>ds.aMatHang[i].TenMH;
        cout<<"Moi ban nhap ma so mat hang thu "<<i+1<<": \n";
        cin>>ds.aMatHang[i].MSMH;
        cout<<"Moi ban nhap so luong mat hang thu "<<i+1<<": \n";
        cin>>ds.aMatHang[i].SoLuong;
        cout<<"Moi ban nhap don gia: \n";
        cin>>ds.aMatHang[i].DonGia;
    }
}
void XuatMatHang(DanhSachMatHang &ds)
{
    char TenMH[201];
    cout<<"Moi ban nhap mat hang muon tim: \n";
    cin>>TenMH;
    bool timhang=false;
    for (int i=0;i<ds.n;i++)
    {
        if (strcmp(ds.aMatHang[i].TenMH,TenMH)==0)
        {
            cout<<"Ten mat hang: "<<ds.aMatHang[i].TenMH<<" \n";
            cout<<"Ma mat hang: "<<ds.aMatHang[i].MSMH<<" \n";
            cout<<"So luong mat hang: "<<ds.aMatHang[i].SoLuong<<" \n";
            cout<<"Don gia: "<<ds.aMatHang[i].DonGia<<" \n";
            timhang=true;
        }
    }
    if (!timhang)
    cout<<"Khong co mat hang dang tim\n"<<endl;
}
void TinhTongSoLuong (DanhSachMatHang ds)
{
    int tong=0;
    for (int i=0;i<ds.n;i++)
    {
        tong+=ds.aMatHang[i].SoLuong;
    }
    cout<<"Tong so luong mat hang trong kho: "<<tong;
}
int main()
{
    MatHang mh;
    DanhSachMatHang ds;
    NhapMatHang(ds);
    XuatMatHang(ds);
    TinhTongSoLuong(ds);
}
    
