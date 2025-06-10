#include <iostream>
using namespace std;

// Sử dụng mảng
struct QueueInt {
    int front;
    int rear;
    int size;
    int count;
    int* arr;
};

// Hàm tạo hàng đợi rỗng
void InitStack(QueueInt &q, int size) {
    q.front = q.rear = -1;
    q.count = 0;
    q.size = size;
    q.arr = new int[q.size];
}

// Hàm kiểm tra hàng đợi rỗng
bool IsEmpty(QueueInt &q) {
    return q.count == 0;
}

// Hàm kiểm tra hàng chờ có đầy không
bool IsFull(QueueInt &q) {
    return q.count == q.size;
}

// Hàm lấy phần tử vào đầu tiên ra khỏi hàng
int PopStack(QueueInt &q) {
    if (IsEmpty(q)) {
        cout << "Hàng đợi rỗng!\n";
        return -1;
    }
    int x = q.arr[q.front];
    q.front = (q.front + 1) % q.size;
    q.count--;
    return x;
}

// Thêm n vào hàng đợi
void PushStack(QueueInt &q, int n) {
    if (IsFull(q)) {
        cout << "Hàng đợi đầy!\n";
        return;
    }
    if (IsEmpty(q)) q.front = 0;
    q.rear = (q.rear + 1) % q.size;
    q.arr[q.rear] = n;
    q.count++;
}

// Xem đầu hàng đợi
int PeekStack(QueueInt &q) {
    if (IsEmpty(q)) return -1;
    return q.arr[q.front];
}

// Xóa bỏ hàng đợi
void Clear(QueueInt &q) {
    q.front = q.rear = -1;
    q.count = 0;
}

// Dùng danh sách liên kết
struct Node {
    int info;
    Node* next;
};

struct LinkedQueueInt {
    Node* front;
    Node* rear;
    int count;
};

void Init(LinkedQueueInt &q) {
    q.front = q.rear = nullptr;
    q.count = 0;
}

Node* CreateNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = nullptr;
    return p;
}

bool IsEmpty(LinkedQueueInt &q) {
    return q.front == nullptr;
}

// Thêm vào hàng đợi
void Enqueue(LinkedQueueInt &q, int x) {
    Node* p = CreateNode(x);
    if (IsEmpty(q)) q.front = p;
    else q.rear->next = p;
    q.rear = p;
    q.count++;
}

// Lấy phần tử ra khỏi hàng đợi
int Dequeue(LinkedQueueInt &q) {
    if (IsEmpty(q)) {
        cout << "Hàng đợi rỗng!\n";
        return -1;
    }
    Node* p = q.front;
    int x = p->info;
    q.front = p->next;
    if (q.front == nullptr) q.rear = nullptr;
    delete p;
    q.count--;
    return x;
}

// Xem đầu hàng đợi
int Peek(LinkedQueueInt &q) {
    if (IsEmpty(q)) return -1;
    return q.front->info;
}

// Xóa hàng đợi
void Clear(LinkedQueueInt &q) {
    while (!IsEmpty(q)) {
        Dequeue(q);
    }
}

int main() {
    // Khai báo và khởi tạo hàng đợi dùng mảng
    QueueInt q;
    InitStack(q, 5);
    
    // Thêm phần tử vào hàng đợi
    cout << "Đẩy phần tử vào hàng đợi (Dùng mảng):\n";
    PushStack(q, 10);
    PushStack(q, 20);
    PushStack(q, 30);
    PushStack(q, 40);
    PushStack(q, 50);
    
    // Xem phần tử đầu tiên
    cout << "Phần tử đầu hàng đợi: " << PeekStack(q) << endl;
    
    // Lấy phần tử ra khỏi hàng đợi
    cout << "Lấy phần tử ra khỏi hàng đợi (Dùng mảng):\n";
    while (!IsEmpty(q)) {
        cout << PopStack(q) << " ";
    }
    cout << endl;
    Clear(q);
    
    // Khai báo và khởi tạo hàng đợi dùng danh sách liên kết
    LinkedQueueInt linkedQueue;
    Init(linkedQueue);
    
    // Thêm phần tử vào hàng đợi
    cout << "\nĐẩy phần tử vào hàng đợi (Dùng danh sách liên kết):\n";
    Enqueue(linkedQueue, 15);
    Enqueue(linkedQueue, 25);
    Enqueue(linkedQueue, 35);
    Enqueue(linkedQueue, 45);
    Enqueue(linkedQueue, 55);
    
    // Xem phần tử đầu tiên
    cout << "Phần tử đầu hàng đợi: " << Peek(linkedQueue) << endl;
    
    // Lấy phần tử ra khỏi hàng đợi
    cout << "Lấy phần tử ra khỏi hàng đợi (Dùng danh sách liên kết):\n";
    while (!IsEmpty(linkedQueue)) {
        cout << Dequeue(linkedQueue) << " ";
    }
    cout << endl;
    Clear(linkedQueue);
    return 0;
}
