#include <iostream>
#include <string>
using namespace std;
#define MAX 20
struct LoaiHoa 
{
    string Ten,DVT;    
    int SoLuong,DonGia;   
};
struct DanhSachLoaiHoa 
{
    LoaiHoa aLoaiHoa[MAX];
    int n;
};
void NhapDanhSach(DanhSachLoaiHoa &ds) 
{
    cout << "Moi nhap so luong loai hoa: ";
    cin >> ds.n;
    cin.ignore();
    cout << "Moi nhap thong tin cac loai hoa: \n";
    for (int i = 0; i < ds.n; i++) 
    {
        cout << "Loai hoa thu " << i + 1 << ": \n";
        cout << "+ Moi nhap ten loai hoa: \n";
        getline(cin, ds.aLoaiHoa[i].Ten);
        cout << "+ Moi nhap so luong hoa hien co: \n";
        cin >> ds.aLoaiHoa[i].SoLuong;
        cout << "+ Moi nhap don gia: \n";
        cin >> ds.aLoaiHoa[i].DonGia;
        cin.ignore();
        cout << "+ Moi nhap don vi tinh: \n";
        getline(cin, ds.aLoaiHoa[i].DVT);
    }
}
void XuatDanhSach(const DanhSachLoaiHoa &ds) 
{
    cout << "Danh sach cac loai hoa: \n";
    for (int i = 0; i < ds.n; i++) 
    {
        cout << "Hoa thu " << i + 1 << ": \n";
        cout << "Ten: " << ds.aLoaiHoa[i].Ten << "\n";
        cout << "So luong: " << ds.aLoaiHoa[i].SoLuong << "\n";
        cout << "Gia tien: " << ds.aLoaiHoa[i].DonGia << "\n";
        cout << "Don vi tinh: " << ds.aLoaiHoa[i].DVT << "\n";
    }
}
int TimLoaiHoa(const DanhSachLoaiHoa &ds, const string &tenloai) 
{
    for (int i = 0; i < ds.n; i++) 
    {
        if (ds.aLoaiHoa[i].Ten == tenloai) 
        {
            return i;
        }
    }
    return -1;
}

void XuLyBanHoa(DanhSachLoaiHoa &ds, const string &tenloai, int soluong) 
{
    int m = TimLoaiHoa(ds, tenloai);
    if (m != -1) 
    {
        if (soluong <= ds.aLoaiHoa[m].SoLuong) 
        {
            cout << "Gia tien: " << soluong * ds.aLoaiHoa[m].DonGia << endl;
            ds.aLoaiHoa[m].SoLuong -= soluong;
        } else 
        {
            cout << "Khong du so luong khach yeu cau" << endl;
        }
    } 
    else 
    {
        cout << "Khong ton tai hoa nay" << endl;
    }
}
int main() 
{
    DanhSachLoaiHoa ds;
    string tenloai;
    int soluong;
    NhapDanhSach(ds);
    cout << "Cac loai hoa cua tiem\n";
    XuatDanhSach(ds);
    cout << "\n";
    cout << "Moi nhap ten loai hoa muon tim: ";
    getline(cin, tenloai);
    cout << "Moi nhap so luong muon mua: ";
    cin >> soluong;
    XuLyBanHoa(ds, tenloai, soluong);
}
