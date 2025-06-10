// BT 6
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a,b,c,d,max,min;
    cout<<"Nhap 4 so:";
    cin>>a>>b>>c>>d;
    max =a;
    if (b>max) max=b;
    if (c>max) max=c;
    if (d>max) max=d;
    min =a;
    if (b<min) min=b;
    if (c<min) min=c;
    if (d<min) min=d;
    cout<<"GTLN, GTNN:"<<max<<" "<<min;
}
