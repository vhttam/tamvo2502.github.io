#include <stdio.h>
#define FO "Data.out"
#define MAX 100
void NhapMang1C(int a[],int &n)
{
    //Sinh vien tu cai dat
    printf("Moi ban nhap so luong so nguyen: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
    printf("Moi ban nhap so nguyen thu %d:",i);
    scanf("%d",&a[i]);
    }
}
void OutputData(int a[],int n)
{
    FILE *fo;
    fo=fopen(FO,"wt");
    if (fo==NULL)
    {
        printf("Khong the tao file");
        return;
    }
    fprintf(fo,"%d\n",n);
    for (int i=0;i<n;i++)
    {
        fprintf(fo,"%d",a[i]);
        fprintf(fo,"\n");
    }
    fclose(fo);
}
int main()
{
    int a[MAX];
    int n;
    NhapMang1C(a,n);
    OutputData(a,n);
    return 0;
}