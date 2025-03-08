#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
#define DSN "DaySoNguyen.inp"
void DuLieuDauVao(int* n)
{
    FILE *dsn;
    dsn=fopen(DSN,"rt");
    if (dsn==NULL)
    {
        cout<<"Khong the doc file\n";
        return;
    }
    fscanf(dsn,"%d",n);
    cout<<*n<<"\n";
    int* daysonguyen = new int[*n];
    for (int i=0;i<*n;i++)
    {
        fscanf(dsn,"%d",&daysonguyen[i]);
    }
    for (int i=0;i<*n;i++)
    {
        cout<<daysonguyen[i]<<" ";
    }
    fclose(dsn);
}
int main()
{
    int n;
    DuLieuDauVao(&n);
}