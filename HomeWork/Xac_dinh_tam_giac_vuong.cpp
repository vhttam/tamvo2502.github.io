#include <iostream>
#include <cmath>
using namespace std;
struct striangle{int a; int b; int c;};
int main ()
{
    double S;
double P=0;
double v=0;
    int n;
    cout<<"Moi nhap so luong tam giac: ";
    cin>>n;
    striangle st[n];
    for (int i=0; i <= n-1;i++){
    cout<<"Moi nhap do dai canh a "<<i+1<<" thu: ";
    cin>>st[i].a;
    cout<<"Moi nhap do dai canh b "<<i+1<<" thu: ";
    cin>>st[i].b;
    cout<<"Moi nhap do dai canh c "<<i+1<<" thu: ";
    cin>>st[i].c;
}
int t=0;
for (int i=0;i<=n-1;i++){
    double p=(st[i].a+st[i].b+st[i].c)/2;
    if ((st[i].a+st[i].b > st[i].c)&&(st[i].a+st[i].c>st[i].b)&&(st[i].b+st[i].c>st[i].a)){
if((st[i].a*st[i].a+st[i].b*st[i].b==st[i].c*st[i].c)||(st[i].a*st[i].a+st[i].c*st[i].c==st[i].b*st[i].b)||(st[i].b*st[i].b+st[i].c*st[i].c==st[i].a*st[i].a))
{
     S=((1/2*(st[i].a*st[i].b))||(1/2*(st[i].a*st[i].c))||(st[i].b*st[i].c));
     t+=1;
}
    else {
        cout<<"Khong phai la tam giac vuong\n";
        v=sqrt(p*(p-st[i].a)*(p-st[i].b)*(p-st[i].c));
    }
    P=P+S+v;
    }
    else cout<<i+1<<"Khong phai tam giac";
}
cout<<"Co "<<t<<" tam giac vuong\n";
for (int i=0;i<=n-1;i++)
{
    cout<<"tam giac thu "<<i+1<<" co do dai cac canh la: "<<st[i].a<<" "<<st[i].b<<" "<<st[i].c<<"\n";
}
cout<<"Tong dien tich cac tam giac: "<<P;
}
