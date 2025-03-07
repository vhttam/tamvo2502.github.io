#include <iostream>
#include <cmath>
using namespace std;
/* Nhập số m, tính tổng tăng dần từ 0 đến khi s vượt qua m thì trả lại số lần thực hiện phép toán */
int find_n (int m) {
    int n = 1;
    int s = 0;
    while (s <=m)
    {
        s+=n;
        n++;
    }
    return n-1;
}
//nhap toi khi dung
int nhapmatkhau (int n)
{
    while (n != 123)
    {
    cout<<"Moi nhap lai mat khau: ";
    cin>>n;
    }
    return n;
}
int main()
{
    int n;
    cout<<"Moi nhap mat khau: ";
    cin>>n;
    int so = nhapmatkhau(n);
    cout<<"Mat khau dung la: "<<so<<endl;
    int m;
    cout<<"moi nhap so m: ";
    cin>>m;
    cout<<"ket qua:";
    cout<<find_n(m);
}

