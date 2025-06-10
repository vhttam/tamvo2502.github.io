#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h> 
#define MAX 100
using namespace std;
int main()
{
    int n;
    printf("+ Day so a\n");
    printf("Moi ban nhap so luong phan tu: ");
    scanf("%d",&n);
    int a[MAX];
    for (int i=0;i<n;i++)
    {
        printf("Phan tu %d: ",i);
        scanf("%d",&a[i]);
    }
    int b[MAX],c[MAX];
    int x=0,y=0;
    for (int i=0;i<n;i++)
    {
        if (a[i] % 2 ==0)
        {
            b[x++]=a[i];
        }
        else 
        {
            c[y++]=a[i];
        }
    }
    printf("+ Day so b chua so chan\n");
    printf("Day so co %d phan tu: ",x);
    for (int i=0;i<x;i++)
    {
        printf("%d ",b[i]);
    }
    printf("\n");
    printf("+ Day so c\n");
    printf("Day so co %d phan tu: ",y);
    for (int i=0;i<y;i++)
    {
        printf("%d",c[i]);
    }

}
