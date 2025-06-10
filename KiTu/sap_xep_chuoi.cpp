#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1000
void sapxep(char* s)
{
    sort(s,s+strlen(s));
}
int main()
{
    char s[MAX];
    cout<<"Moi ban nhap chuoi ki tu: \n";
    cin.getline(s,MAX);
    sapxep(s);
    cout<<"chuoi ki tu sau khi ssap xep: "<<s;
}
