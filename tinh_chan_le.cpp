#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
using namespace std;
bool kiem_tra_chan_le(int* a[],int n)
{
    for (int i=0;i<n;i++)
    {
        if (i % 2 == 0)
        {
            if (*a[i] % 2 !=0)
            return false;
        }
        else if (i % 2 != 0)
        {
            if (*a[i] % 2 ==0)
            return false;
        }
    }
    return true;
}
bool kiem_tra_toan_chan(int* a[],int n)
{
    for (int i=0;i<n;i++)
    {
        if (*a[i] % 2 != 0)
        return false;
    }
    return true;
}
int main()
{
    int n;
    printf("Moi ban nhap so luong phan tu: ");
    scanf("%d",&n);
    int* a[n];
    for (int i=0;i<n;i++)
    {
        a[i] = (int*)malloc(sizeof(int));
        printf("Phan tu %d: ",i);
        scanf("%d",a[i]);
    }
    if (kiem_tra_chan_le(a,n))
    printf("+ Day co tinh chat chan le\n");
    else 
    {
        printf("+ Day khong co tinh chat chan le\n");
    }
    if (kiem_tra_toan_chan(a,n))
    printf("+ Day co tinh chat toan chan\n");
    else
    {
        printf("+ Day khong co tinh chat toan chan\n");
    }
}