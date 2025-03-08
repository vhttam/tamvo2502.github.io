#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define NT "NT.inp"
#define OUT "NT.out"
int* dayso = nullptr;
void DuLieuDauVao(int* n)
{
    FILE *nt;
    nt=fopen(NT,"rt");
    if (nt==NULL)
    {
        cout<<"Khong the doc file";
        return;
    }
    fscanf(nt,"%d",n);;
    dayso=new int[*n];
    for (int i=0;i<*n;i++)
    {
        fscanf(nt,"%d",&dayso[i]);
    }
    fclose(nt);
}
bool SoNguyenTo(int num)
{
    if (num<2)
    return false;
    for (int j=2;j<=sqrt(num);j++)
    {
        if (num%j==0)
        return false;
    }
    return true;
}
void DuLieuDauRa(int n)
{
    FILE *nt;
    nt=fopen(OUT,"wt");
    if (nt==NULL)
    {
        cout<<"Khong the ghi file";
        return;
    }
    int* songuyento=new int[n];
    int dem=0;
    for (int i=0;i<n;i++)
    {
        if (SoNguyenTo(dayso[i]))
        {
            songuyento[dem++]=dayso[i];
        }
    }
    sort(songuyento,songuyento+dem);
    fprintf(nt,"%d\n",dem);
    for (int i=0;i<dem;i++)
    {
        fprintf(nt,"%d",songuyento[i]);
        fprintf(nt," ");
    }
    fclose(nt);
}
int main()
{
    int n;
    DuLieuDauVao(&n);
    DuLieuDauRa(n);
}