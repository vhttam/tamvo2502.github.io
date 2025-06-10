#include <iostream>
#include <cmath>
using namespace std;
#define maxm 100
#define maxn 100
void input_array (int a[maxm][maxn], int &m,int &n){
    cout<<"Moi nhap so hang:";
    cin>> m;
    cout<<"Moi nhap so cot:";
    cin>> n;
    cout<<"Nhap phan tu cua mang:\n";
    for (int i=1; i<=m;i++) {
        for (int j=1; j<=n;j++){
            cout<<"a["<<i<<"]"<<"["<<j<<"]= ";
            cin>>a[i][j];
        }
    }
}
void output_array(int a[maxm][maxn],int m, int n){
    for (int i=1; i<=m;i++) {
        for (int j=1; j<=n;j++){
           cout<<"a["<<i<<"]"<<"["<<j<<"]= "<<a[i][j]<<" ";
}
cout<<endl;
}
}
void max_array(int a[maxm][maxn],int m,int n){
    int t=a[1][1];
    for (int i=1; i<=m;i++){
        for( int j= 1; j<=n;j++){
            if(t< a[i][j])
            {
                t =a[i][j];
            }
        }
    }
    cout<<t;
}
bool is_prime (int k)
{
     if (k < 2) return 0;
     for ( int i=2;i <=sqrt(k);i++){
        if (k % i ==0){
        return 0;}
     }
     return 1;
}
void count_prime_row(int a[maxm][maxn],int m,int n){
    int k;
    for (int i=1;i<=m;i++){
        int f = 0;
        for(int j=1;j<=n;j++){
            k=a[i][j];
            if(is_prime(k))
            f++;
    }
    cout<<"\nHang "<<i<<" co "<<f<<" so nguyen to";
}
}
void sort_row(int a[maxm][maxn],int m,int n){
    for (int i = 1;i <= m;i++){
        for (int j = 1;j <= n;j++){
            for(int k = 1;k <= n-j;k++){
            if ( a[i][k] > a[i][k+1])
            {
                int temp = a[i][k];
                a[i][k] = a[i][k+1];
                a[i][k+1] = temp;
            }
        }
        }
        cout<<"\n Sap xep theo thu tu tu be den lon hang thu "<<i<<" la: ";
        for (int j=1;j<=n;j++)
        cout<<a[i][j]<<" \n";
    }
    cout<<endl;
}
int main()
{
    int a[maxm][maxn];
    int m,n,t;
    input_array(a,m,n);
    cout<<"Mang hai chieu vua nhap la:\n";
     output_array(a,m,n);
     cout<<"Phan tu lon nhat trong mang la:\n";
     max_array(a,m,n);
     count_prime_row(a,m,n);
     sort_row(a,m,n);
}
