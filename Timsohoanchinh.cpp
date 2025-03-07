#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
//Tìm số hoàn chỉnh
int main ()
{
    int n;
    int s=0;
    cin>>n;
    for (int i = 1;i < n;i++)
    {
        if (n % i==0)
        {
            s+=i;
        }
        else
        s=s;
    }
    if (s==n)
    cout<<n<<" la so hoan chinh";
    else
    cout<<n<<" khong la so hoan chinh";
}