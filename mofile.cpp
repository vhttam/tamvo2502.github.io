#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //Con trỏ chứa địa chỉ mở file filename.txt ở dạng viết
    FILE *fptr;
    fptr=fopen("filename.txt","wt");
    // Nếu con trỏ = NULL thì báo lỗi mở filefile
    if (fptr == NULL) {
    cout << "Error opening file!" << endl;
    return 1;
}
else
{
    // Ngược lại ghi vào file văn bản dưới
    fprintf(fptr,"hello TerRon");
    fclose(fptr);
    return 0;
}
}