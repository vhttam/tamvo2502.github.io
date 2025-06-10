#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h> 
#define MAX 100
using namespace std;
bool nguyen_am(char* c)
{
    *c = tolower(*c);
    return (*c=='a'||*c=='o'||*c=='u'||*c=='e'||*c=='i');
}
int main()
{
    int n;
    printf("Moi ban nhap so luong phan tu: ");
    scanf("%d",&n);
    char a[MAX];
    for (int i=0;i<n;i++)
    {
        printf("Phan tu %d:",i);
        scanf(" %c",&a[i]);
    }
    int m=0;
    char b[MAX];
    for (int i=0;i<n;i++)
    {
        if (nguyen_am(&a[i]))
        {
            b[m]=a[i];
            m++;
        }
    }
    printf("Day b co cac ki tu: \n");
    for (int i=0;i<m;i++)
    {
        printf("%c ",b[i]);
    }
}
