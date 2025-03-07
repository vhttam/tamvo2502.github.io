#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// Giới hạn của nx,ny,nz, giá trị của từng phần tử
const int max_size =1000;
int maximum = 10000;
void phantuchung (int nx, int ny, int nz,int x[],int y[],int z[])
{
  int i=0, k=0,j=0;
  int m=0;
  int t[max_size];
  while (i<nx && k<ny && j<nz)
  {
    // Tìm phần tử chung
    if (x[i]==y[k] && y[k]==z[j])
    {
        // bỏ qua các phần tử bị lặp lại
        bool phan_tu_lap = false;
        for (int l=0;l<m;l++)
        {
            if (t[l]==x[i])
            {
            phan_tu_lap= true;
            break;
            }
        }
        if (!phan_tu_lap)
        {
            t[m]=x[i];
            m++;
        }
        t[m]=x[i];
        i++;
        j++;
        k++;
    }
    // tìm min nếu ko bằng nhau
    else 
    {
        // trường hợp x nhỏ nhất
        if (x[i]<y[k])
        {
            if (x[i]<z[j])
            i++;
            else
            j++;
        }
        // x lớn hơn y nên xét y hay z nhỏ hơn
        else if (y[k]<z[j]) 
        k++;
        else
        j++;
    }
  }
  if (sizeof(t[m])==0)
  {
    cout<<sizeof(t[m]);
  }
  //In số lượng phần tử chung
  cout<<m<<endl;
  //Sắp xếp từ bé đến lớn
  sort(t,t+m);
  //In các phần tử chung ra màn hình
  for (int i = 0; i<m ; i++)
  {
    cout<<t[i]<<" ";
  }
  cout<<endl;
}
int main()
{
    int nx,ny,nz;
    int x[max_size];
    int y[max_size];
    int z[max_size];
    //Nhập số phần tử của mảng và giá trị của mỗi phần tử
    cin>>nx;
    if (nx>1000)
    {
        cin>>nx;
    }
    for (int i=0;i<nx;i++)
    {
        // Cho nhập lại nếu vượt quá giới hạn
        do
        {
        cin>>x[i];
        }
        while (x[i]>maximum);
    }
    cin>>ny;
    if (ny>1000)
    {
        cin>>ny;
    }
    for (int i=0;i<ny;i++)
    {
        do
        {
        cin>>y[i];
        }
         while (y[i]>maximum);
    }
    cin>>nz;
    if (nz>1000)
    {
        cin>>nz;
    }
    for (int i=0;i<nz;i++)
    {
        do
        {
        cin>>z[i];
        }
        while (z[i]>maximum);
    }
    cout<<endl;
    // sắp xếp từ bé đến lớn
    sort(x,x + nx);
    sort(y,y + ny);
    sort(z,z + nz);
    // dùng hàm tìm phần tử chung
    phantuchung(nx, ny, nz, x, y, z);
}