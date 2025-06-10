#include <iostream>
#include <cstring>
#define MAX 1000
using namespace std;
void chen_ki_tu(char* s,int k, char c)
{
    int len=strlen(s);
    if (k<0||k>len)
    {
        cout<<"Vị trí "<<k<<" không hợp lệ";
        return;
    }
    for (int i=len;i>=k;i--)
    {
        s[i+1]=s[i];
    }
    s[k]=c;
}
int main()
{
    char s[MAX];
    char b[MAX];
    int k;
    char c;
    cout<<"Moi ban nhap chuoi s: ";
    cin.getline(s,MAX);
    for (int i=0;i<strlen(s);i++)
    {
        b[i]=s[i];
    }
    cout<<"Moi ban nhap vi tri can chen: ";
    cin>>k;
    cout<<"Moi ban nhap ki tu muon chen: ";
    cin>>c;
    chen_ki_tu(s,k,c);
    cout<<"Chuoi \""<<b<<"\" sau khi them ki tu \""<<c<<"\" vao vi tri "<<k<<": "<<s;
}
