#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// Hàm phường trình bậc 2
int phuong_trinh_bac_2 (double a,double b, double c, double &x1, double &x2)
{
    int n=-1;
    if (a ==0)
    {
        if (b==0)
        {
            if (c==0) // Vô số nghiệm
            n=-1;
            else // Vô nghiệm
            n=1;
        }
        else //a = 0, bx + c = 0
        { 
        n=0;
        x1=-c/b;
        }
    }
    else
    {
    double delta =(b*b)-(4*a*c);
    if (delta==0) //Nghiệm kép
    {
        n=0;
        x1= -b/(2*a);
    }
    else if(delta>0) //2 nghiệm phân biệt
    {
        n=2;
        x1= (-b-sqrt(delta))/(2*a);
        x2= (-b+sqrt(delta))/(2*a);
        if (x1>x2) //Sắp xếp x1 bé hơn x2
        {
            float t = x1;
            x1 = x2;
            x2 = t;
        }
    }
    else //Vô nghiệm
    n=1;
    }
    return n;
}
int main()
{
    double a,b,c;
    double x1,x2;
    cin>>a>>b>>c;
    int n = phuong_trinh_bac_2(a,b,c,x1,x2);
    // n = -1 là vô số nghiệm
    // n = 1 là vô nghiệm
    // n = 0 là có 1 nghiệm/nghiệm kép
    // n = 2 là có 2 nghiệm
    if (n==-1)
    {
        cout<<"Phuong trinh co vo so nghiem";
    }
    else if (n==1)
    {
        cout<<"Phuong trinh vo nghiem";
    }
    else 
    {
        if(n==0)
        {
    cout<<"Phuong trinh co 1 nghiem: \n";
    printf("%.2f", x1);
        }
        else if (n==2)
        {
            cout<<"Phuong trinh co 2 nghiem: \n";
            printf("%.2f", x1);
            cout<<" ";//Làm tròn đến 2 chữ số thập phân
            printf("%.2f", x2);
        }
    }
    return 0;
}