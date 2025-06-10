#include <iostream>
#include <cstring>
#define MAX 1000
using namespace std;
int main() 
{
    char s[MAX];
    int k;
    char b[MAX];
    cout<<"Moi ban nhap chuoi s: ";
    cin.getline(s,MAX);
    for (int i=0;i<strlen(s);i++)
    {
        b[i]=s[i];
    }
    cout<<"Moi ban nhap vi tri can xoa: ";
    cin >> k;
    int len=strlen(s);
    if (k>=0 && k<len) 
    {
        for (int i=k;i<len;i++) 
        {
            s[i]=s[i+1];
        }
        cout<<"Chuỗi \""<<b<<"\" sau khi xóa ký tự tại vị trí "<<k<<": "<<s;
    } 
    else 
    {
        cout<<"Vị trí"<<k<<" không hợp lệ";
    }
}
