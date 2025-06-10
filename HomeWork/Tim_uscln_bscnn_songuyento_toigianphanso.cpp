#include <iostream>
#include <cmath>
using namespace std;
// Tìm ước số chung lớn nhất 
int uscln (int a, int b) 
{
     while (b != 0)
     {
      int temp = b;
      b = a % b;
      a = temp;
     }
     return a;
}
// Tìm bội số chung nhỏ nhất
int bscnn (int a, int b)
{
    return (a*b) / uscln(a,b);
}
// Tìm số nguyên tố
int songuyento (int n)
{
    if (n < 2) return 0;
    for ( int i = 2; i <= sqrt(n); i++)
    {
       if (n % i == 0)
       return 0;
    }
    return 1;
}
// toi gian phan so
void toigianphanso(int &tu, int &mau){
int gcd = uscln(tu,mau);
tu /= gcd;
mau /= gcd;
if (mau < 0)
{
     tu = -tu;
     mau = -mau;
}
}
// so sanh phan so
//nhap toi khi dung
// sap xep
int main ()
{
    int a,b,n,tu,mau;
    cout << "moi nhap 2 so:";
    cin >> a >> b;
    cout << "moi nhap so n:";
    cin >> n;
    cout << "uoc so chung lon nhat cua 2 so la:" << uscln(a,b) << endl;
    cout << "boi so chung nho nhat cua 2 so la:" << bscnn(a,b) << endl;
    if (songuyento(n))
    {
    cout<<n<<" la so nguyen to" << endl;
    }
    else
    {
    cout<<n<<" khong phai la so nguyen to" << endl;
    }
    cout << "moi nhap tu so:";
    cin >> tu;
    cout << "moi nhap mau so:";
    cin >> mau;
    if (mau == 0)
    {
    cout<<"Mau khong the bang 0";
    }
    else
    {
    toigianphanso(tu, mau);
    cout<<"Ket qua phan so toi gian la:" << tu << "/" << mau;
    }
}
