#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
//bai 2 tim so nguyen to be hon hoac bang so nguyen n
bool so_nguyen_to(int n)
{
if (n<2)
return false;
    for (int i=2;i<=sqrt(n);i++)
    {
        if (n % i==0)
        return false;
    }
return true;
}
int main()
{
    int n;
    cin>>n;
        for (int i=2;i<=n;i++)
        {
            if (so_nguyen_to(i))
            cout<<i<<" ";
        }
}
