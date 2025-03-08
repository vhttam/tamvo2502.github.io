#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define CS "CapSo.inp"
#define OUT "CapSo.out"
int* dayso = nullptr;
void DuLieuDauVao (int* n,int* k)
{
    FILE *cs;
    cs=fopen(CS,"rt");
    if (cs==NULL)
    {
        cout<<"Khong the doc file";
        return;
    }
    fscanf(cs,"%d",n);
    fscanf(cs,"%d",k);
    dayso=new int[*n];
    for (int i=0;i<*n;i++)
    {
        fscanf(cs,"%d",&dayso[i]);
    }
    fclose(cs);
}
void DuLieuDauRa (int n,int k)
{
    FILE *cs;
    cs=fopen(OUT,"wt");
    if (cs==NULL)
    {
        cout<<"Khong the ghi file";
        return;
    }
    int* capso=new int[n];
    int dem=0;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (dayso[i]+dayso[j]==k)
            {
                capso[dem++]=dayso[i];
                capso[dem++]=dayso[j];
            }
        }
    }
    for (int i=0;i<dem-1;i+=2)
    {
        fprintf(cs,"%d %d\n",capso[i],capso[i+1]);
    }
    for (int i=0;i<dem-1;i+=2)
    {
        cout<<capso[i]<<" "<<capso[i+1]<<endl;
    }
}
int main()
{
    int n;
    int k;
    DuLieuDauVao(&n,&k);
    DuLieuDauRa(n,k);
}