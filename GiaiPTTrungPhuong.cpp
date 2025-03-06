#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// Hàm tính phương trình bậc 2
int phuong_trinh_bac_2 (double a,double b, double c, float &x1, float &x2)
{
    int n=1;
    double delta=b*b-4*a*c;
    if (a==0)
    {
        if (b==0)
        {
            if (c==0)// Trường hợp vô số nghiệm
            n = 1;
            else // Vô nghiệm
            n=0;
        }
        else //a = 0, bx + c = 0
        { 
        n=0;
        x1=-c/b;
        }
    }
    else 
    {
        if (delta == 0)//Trường hợp nghiệm kép
    {
        n= -1;
        x1= -b/(2*a);
    }
        else if (delta > 0)//TTrường hợp 2 nghiệm
    {
        n=2;
        x1= (-b-sqrt(delta))/(2*a);
        x2= (-b+sqrt(delta))/(2*a);
    }
        else //Trường hợp vô nghiệm
        n = 0;
    }
    return n;
}
//Hàm phương trình trùng phương
void phuong_trinh_trung_phuong (float a, float b,float c)
{
    float x1,x2;
    int n = phuong_trinh_bac_2(a,b,c,x1,x2);
    // n = 1 là phương trình vô số nghiệm
    // n = 0 là phương trình vô nghiệm
    // n = -1 là phương trình có nghiệm kép/ hoặc 2 nghiệm
    // n = 2 là phương trình có 2 hoặc 4 nghiệm
    if (n==1)
    {
        cout<<"Phuong trinh co vo so nghiem";
    }
    else if (n==0)
    {
        cout<<"Phuong trinh vo nghiem";
    }
    else if (n==-1)
    {
        int xx = 0;
        // Lưu nghiệm vào y
        float y[2];
        if (x1 > 0)
        {
        y[xx++] =sqrt(x1);
        y[xx++] =-sqrt(x1);
        }
        if (x1==0)
        {
            y[xx++] =-sqrt(x1);
        }
        if (xx>0)
        {
        sort(y,y+xx); // Sắp xếp
        cout<<"Phuong trinh co "<<xx<<" nghiem"<<endl;
        }
        for (int i=0;i<xx;i++)
        {
            printf("%.2f", y[i]);//Làm tròn đến 2 chữ số thập phân
            cout<<" ";
        }
    }
    else if (n == 2)
    {
        int xx = 0;
        // Lưu nghiệm vào y
        float y[4];
        if (x1 > 0)
        {
        y[xx++]=sqrt(x1);
        y[xx++]=-sqrt(x1);
        }
        if (x2 > 0)
        {
        y[xx++]=sqrt(x2);
        y[xx++]=-sqrt(x2);
        }
        if (xx>0)
        {
        sort(y,y+xx);//Sắp xếp
        cout<<"Phuong trinh co "<<xx<<" nghiem"<<endl;
        for (int i=0;i<xx;i++)
        {
            printf("%.2f", y[i]);//Làm tròn đến 2 chữ số thập phân
            cout<<" ";
        }
        }
        else 
        cout<<"Phuong trinh vo nghiem";
    }
}
int main()
{
    float a,b,c;
    // Nhập a,b,c
    cin>>a>>b>>c;
    phuong_trinh_trung_phuong(a,b,c);
    return 0;
}