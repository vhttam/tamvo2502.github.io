#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
#define MS "MangSo.inp"
void DuLieuDauVao(int* n,int *m)
{
    FILE *ms;
    ms=fopen(MS,"rt");
    if (ms==NULL)
    {
        cout<<"Khong the doc file\n";
        return;
    }
    fscanf(ms,"%d",n);
    cout<<*n<<" ";
    fscanf(ms,"%d",m);
    cout<<*m<<"\n";
    int** mangso= new int*[*n];
    for (int i=0;i<*n;i++)
    {
        mangso[i]= new int[*m];
    }
    for (int i=0;i<*n;i++)
    {
        for (int j=0;j<*m;j++)
        {
            fscanf(ms,"%d",&mangso[i][j]);
        }
    }
       for (int i=0;i<*n;i++)
    {
        for (int j=0;j<*m;j++)
        {
            cout<<mangso[i][j]<<" ";
        }
        cout<<"\n";
    }
    fclose(ms);
}
int main()
{
    int n,m;
    DuLieuDauVao(&n,&m);
}