#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// Bai 1 tim so lon nhat trong 2 so
int main()
{
    int a,b;
    cin>>a>>b;
    int s=(a+b+abs(a-b))/2;
    cout<<s;
}