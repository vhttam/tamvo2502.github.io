#include <iostream>
#include <string>
using namespace std;

// ==================== StackInt (cho số nguyên) ====================
typedef struct StackInt {
    int top, size;
    int* arr;
} StackInt;

void InitStack(StackInt &s, int size) {
    s.top = -1;
    s.size = size;
    s.arr = new int[size];
}
bool IsEmpty(StackInt &s) { 
    return s.top == -1; 
}
bool IsFull(StackInt &s) { 
    return s.top == s.size - 1; 
}
void PushStack(StackInt &s, int x) {
    if (!IsFull(s)) 
    s.arr[++s.top] = x;
}
int PopStack(StackInt &s) {
    if (!IsEmpty(s)) 
    return s.arr[s.top--];
    return -1;
}
int PeekStack(StackInt &s) {
    if (!IsEmpty(s)) 
    return s.arr[s.top];
    return -1;
}
void Clear(StackInt &s) { 
    s.top = -1; 
}
// ==================== StackChar (cho ký tự) ====================
typedef struct StackChar {
    int top, size;
    char* arr;
} StackChar;
void InitStack(StackChar &sc, int size) {
    sc.top = -1;
    sc.size = size;
    sc.arr = new char[size];
}
bool IsEmpty(StackChar &sc) { 
    return sc.top == -1; 
}
bool IsFull(StackChar &sc) { 
    return sc.top == sc.size - 1; 
}
void PushStack(StackChar &sc, char x) {
    if (!IsFull(sc)) 
    sc.arr[++sc.top] = x;
}
char PopStack(StackChar &sc) {
    if (!IsEmpty(sc)) 
    return sc.arr[sc.top--];
    return -1;
}
char PeekStack(StackChar &sc) {
    if (!IsEmpty(sc)) 
    return sc.arr[sc.top];
    return -1;
}
void Clear(StackChar &sc) { 
    sc.top = -1; 
}
void DaoSo(StackInt &s) {
    while (!IsEmpty(s)) 
    cout<<PopStack(s)<<" ";
    cout << endl;
}
bool DoiXung(string str) {
    StackChar sc;
    InitStack(sc, str.length());
    for (char ch : str) {
        PushStack(sc,ch);
    }
    for (char ch : str) {
        if (ch != PopStack(sc)) {
            return false;
        }
    }
    delete[] sc.arr;
    return true;
}
void ChuyenDoiNhiPhan(int n){
    if(n==0){
        cout<<"0";
        return;
    }
    StackInt s;
    InitStack(s,32);
    while (n!=0){
        int r=n%2;
        PushStack(s,r);
        n=n/2;
    }
    while (!IsEmpty(s)){
        cout<<PopStack(s);
    }
    delete[] s.arr;
}
// ==================== Chuyển đổi trung tố sang hậu tố ====================
// Xác định độ ưu tiên của các toán tử
int DoUuTien(char op) {
    if (op == '^') 
    return 3;
    if (op == '*' || op == '/') 
    return 2;
    if (op == '+' || op == '-') 
    return 1;
    return 0;
}
// Chuyển từ trung tố sang hậu tố
string ChuyenDoiHauTo(string bieuthuc) {
    StackChar sc;
    InitStack(sc, bieuthuc.length());
    string hauTo = "";
    for (char ch : bieuthuc) {
        if (isalnum(ch)) {
            // Toán hạng (chữ số hoặc chữ cái), thêm trực tiếp vào hậu tố
            hauTo += ch;
        } 
        else if (ch == '(') {
            // Mở ngoặc, đẩy vào stack
            PushStack(sc, ch);
        } 
        else if (ch == ')') {
            // Đóng ngoặc, pop tới khi gặp mở ngoặc '('
            while (!IsEmpty(sc) && PeekStack(sc) != '(') {
                hauTo += PopStack(sc);
            }
            PopStack(sc);  // Bỏ dấu '(' ra khỏi stack
        } 
        else {
            // Toán tử: pop các toán tử có độ ưu tiên >= hiện tại
            while (!IsEmpty(sc) && DoUuTien(PeekStack(sc)) >= DoUuTien(ch)) {
                hauTo += PopStack(sc);
            }
            PushStack(sc, ch);
        }
    }
    // Pop hết các toán tử còn lại trong stack
    while (!IsEmpty(sc)) {
        hauTo += PopStack(sc);
    }
    delete[] sc.arr;  // Giải phóng bộ nhớ
    return hauTo;
}

// ==================== Hàm main kiểm tra ====================
int main() {
    StackInt s;
    int size;
    cout<<"Nhập độ dài mảng: ";
    cin>>size;
    InitStack(s, size);
    DaoSo(s);
    string str;
    cout<<"Nhập chuỗi: ";
    cin>>str;
    if(DoiXung(str)){
        cout<<"Chuỗi này đối xứng\n";
    }
    else
    cout<<"Chuỗi này không đối xứng\n";
    int n;
    cout<<"Nhập số thập phân cần chuyển đổi: ";
    cin>>n;
    ChuyenDoiNhiPhan(n);
    cout<<"\n";
    string TrungTo;
    cout << "Nhập biểu thức trung tố: ";
    cin >> TrungTo;
    string hauTo = ChuyenDoiHauTo(TrungTo);
    cout << "Biểu thức hậu tố: " << hauTo << endl;
    return 0;
}
