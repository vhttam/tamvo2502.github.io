#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h> 
#define MAX 100
using namespace std;
int main()
{
    int n,m;
    printf("+ Day so a\n");
    printf("Moi nhap so luong phan tu: ");
    scanf("%d",&n);
    float a[MAX];
    for (int i=0;i<n;i++)
    {
        printf("Phan tu %d: ",i);
        scanf("%f",&a[i]);
    }
    printf("+ Day so b\n");
    printf("Moi nhap so luong phan tu: ");
    scanf("%d",&m);
    float b[MAX];
    for (int i=0;i<m;i++)
    {
       printf("Phan tu %d: ",i);
       scanf("%f",&b[i]);
    }
    float c[MAX+MAX];
    int i=0,j=0,k=0;
    while (i<n && j<m)
    {
       if (a[i]<b[j])
       {
        c[k]=a[i];
        k++;
        i++;
       }
       else
       {
        c[k]=b[j];
        k++;
        j++;
       }
    }
    while (i<n)
    {
    c[k++]=a[i++];
    }
    while (j<m)
    {
    c[k++]=b[j++];
    }
    printf("Day c gom cac phan tu: ");
    for (int i=0;i<k;i++)
    {
    printf("%.1f ",c[i]);
    }
}
