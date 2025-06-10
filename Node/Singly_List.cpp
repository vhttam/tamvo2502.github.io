#include <iostream>
using namespace std;
typedef struct node{
    int info;
    // next trỏ tới node kế tiếp trong danh sách
    struct node *next;
    } Node;
    //pHead trỏ tới node đầu tiên trong danh sách
    Node* pHead = NULL;
bool IsEmpty(Node* pHead) {
    //nếu pHead==NULL-->Trả về true, ngược lại thì false
    return(pHead == NULL);
}
void Init(Node* &pHead) {
    pHead=NULL;
}
Node* CreateNode(int x) {
    Node* p=new Node;
    p->info=x;
    p->next=NULL;
    return p;
}
//Dùng while
void ShowList(Node* pHead) {
    Node* p=pHead;
    if (p==NULL)
    cout<<"\n Danh sach rong\n";
    else
    while (p!=NULL)
    {
        printf("%d \t",p->info);
        p = p->next;
    }
}
//Dùng for
void ShowList1(Node* pHead)
{
    if(pHead == NULL)
    printf("\n Danh sach rong");
    else
    for (Node* p = pHead; p!=NULL; p = p->next)
    printf("%d \t",p->info);
}
//Tìm kiếm tuần tự phần tử có nội dung là x
Node* Find(Node* pHead,int x){
    Node* p=pHead;
    bool found = false;
    while (p!=NULL&&!found)
    {
        if (p->info==x){
            found=true;
        }
        else
        p = p->next;
    }
    if(!found)
    p=NULL;
    return p;
}
//Tìm x trong danh sách theo thứ tự từ bé đến lớn
Node* FindOrder(Node* pHead, int x)
{
// Tìm x trong danh sách đã có thứ tự
    bool found = false;
    Node *p = pHead;
    while ((p != NULL) && (! found))
    if (p->info == x)
    found = true;
    else if (p->info < x)
    p = p->next;
    else
    p = NULL;
    if (! found)
    p = NULL;
    return p;
}
//Chèn vào đầu danh sách
void InsertFirst(Node* &pHead, int x)
{
    Node* p = CreateNode(x);
    p->next = pHead;
    pHead = p;
}
//Chèn vào sau p
void InsertAfter(Node* p, int x)
{
if(p!=NULL){
// Thêm vào ngay sau item
    Node* q = CreateNode(x);
    q->next = p->next;
    p->next = q;
    }
}
//Chèn x vào vị trí trong danh sách theo thứ tự từ bé đến lớn
void InsertOrder(Node* &pHead, int x)
{
// Thêm x vào danh sách có thứ tự tăng dần
    Node* tp;
    Node* p = pHead;
    bool cont = true;
    while ((p != NULL) && cont)
    if (p->info < x)
    {
        tp = p;
        p = p->next;
    }
    else cont = false;
// Xen nút q vào giữa nút p và nút tp
    if(p == pHead)
    InsertFirst(pHead, x);
    else
    InsertAfter(tp, x);
}
//Xóa kí tự đầu
void DeleteFirst(Node* &pHead)
{
    if (IsEmpty(pHead))
    printf("List is empty!");
    else {
    Node *p = pHead;
    pHead = pHead->next;
    delete p;
}
}
//Xóa sau kí tự p
void DeleteAfter(Node* p)
{
if (p==NULL || p->next ==NULL)
//kiem tra nut sau p co ton tai ko
printf("Khong the xoa nut nay!");
else {
    Node* q = p->next;
    p->next = q->next;
    delete q;
}
}
//Tìm và bỏ x trong danh sách 
Node* Remove(Node* &pHead, int x)
// Tìm và bỏ x trong danh sách first chưa có thứ tự
{
    Node *tp;
    Node *p = pHead;
    bool found = false;
    while ((p != NULL) && !found) {
    if (p->info != x)
    {
        tp = p;
        p = p->next;
    }
    else
    found = true;
    }
    if (found)
    {
        if (p == pHead) // Loại bỏ phần tử đầu tiên
        pHead = p->next;
        else
        tp->next = p->next;
        delete p;
    }
    return NULL;
}
//Tìm và xóa x trong danh sach theo thứ tự từ bé đến lớn
Node* RemoveOrder(Node* &pHead, int x)
// Tìm và bỏ x trong danh sách first đã có thứ tự
{
    Node *tp;
    Node *p = pHead;
    bool found = false;
    while ((p != NULL) && !found) {
    if (p->info < x)
    {
        tp = p;
        p = p->next;
    }
    else if( p->info == x) found = true;
    else p = NULL;
    }
    if (found)
    {
        if (p == pHead) // Loại bỏ phần tử đầu tiên
        pHead = p->next;
        else
        tp->next = p->next;
        delete p;
    }
    return NULL;
}
//Xóa toàn bộ danh sách
void ClearList(Node* &pHead)
// Xóa toàn bộ danh sách
{
    Node* p;
    while (pHead!=NULL){
    p = pHead;
    pHead = p->next;
    delete p;
    } // hết while
} // hết ClearList
//Sắp xếp các phần tử trong danh sách
void SelectionSort(Node* &pHead)
// Sắp xếp danh sách tăng dần
{
    int vmin;
    for(Node* p = pHead; p->next != NULL; p = p->next){
    vmin = p->info;
    Node* pmin = p;
    for(Node* q = p->next;q != NULL;q = q->next){
        if (q->info < vmin) {
            vmin = q->info;
            pmin = q;
        } // hết if
    } // hết for q
    // pmin (đang chưa giá trị nhỏ nhất) đổi thành p(giá trị đang xét)
    pmin->info = p->info;
    // p(giá trị đang xét) trở thành vmin(giá trị nhỏ nhất)
    p->info = vmin;
    } // hết for p
} // hết Sort
int main(){
    Node* pHead = NULL;
    Init(pHead);
    
    int n, x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        if (pHead=NULL)
        {
            cin >> x;
            InsertFirst(pHead, x);
        }
    }
    ShowList(pHead);
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    Node* find = Find(pHead, x);
    if (find)
        cout << "Tim thay: " << x << endl;
    else
        cout << "Khong tim thay!\n";

    cin >> x;
    if (pHead != NULL && pHead->next != NULL) {
        InsertAfter(pHead->next, x);
        ShowList(pHead);
    } else {
        cout << "Danh sach khong du phan tu de chen!\n";
    }

    cout << "Xoa phan tu dau danh sach:\n";
    DeleteFirst(pHead);
    ShowList(pHead);

    if (pHead != NULL && pHead->next != NULL) {
        DeleteAfter(pHead);
        ShowList(pHead);
    } else {
        cout << "Danh sach khong du phan tu de xoa!\n";
    }

    cout << "Nhap gia tri can xoa: ";
    cin >> x;
    Remove(pHead, x);
    ShowList(pHead);

    cout << "Sap xep danh sach:\n";
    SelectionSort(pHead);
    ShowList(pHead);

    cout << "Xoa toan bo danh sach:\n";
    ClearList(pHead);
    ShowList(pHead);

    return 0;
}
