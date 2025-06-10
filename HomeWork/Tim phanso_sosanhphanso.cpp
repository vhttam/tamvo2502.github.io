#include <iostream>
#include <cmath>
using namespace std;
// tim uscln
int uscln (int a,int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
// phan so
struct phanso
{
    int tu;
    int mau;
};
void toigianphanso (phanso &ps)
{
    int gcd = uscln(ps.tu,ps.mau);
    ps.tu /=gcd;
    ps.mau /=gcd;
    if (ps.mau<0)
    {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
}
// so sanh phan so
int sosanhphanso (phanso ps1, phanso ps2)
{
    int lhs =ps1.tu * ps2.mau;
    int rhs = ps1.mau * ps2.tu;
    if (lhs == rhs) return 0;
    else if (lhs > rhs) return 1;
    else return -1;
}
// sap xep
int main ()
{
    phanso ps1,ps2;
    cout<<"nhap tu va mau so thu nhat:";
    cin>>ps1.tu>>ps1.mau;
    cout<<"nhap tu va mau so thu hai:";
    cin>>ps2.tu>>ps2.mau;
    toigianphanso(ps1);
    toigianphanso(ps2);
int ketqua = sosanhphanso(ps1,ps2);
if (ketqua ==0)
cout<<"hai phan so bang nhau";
else if (ketqua > 0)
cout<<"phan so 1 lon hon phan so 2";
else
cout<<"phan so 2 lon hon phan so 1";
}
