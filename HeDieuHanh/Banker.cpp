#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int P = 0, R = 0;
vector<vector<int>> maxMatrix;
vector<vector<int>> allocation;
vector<vector<int>> need;
vector<int> available;

// Hàm nhập dữ liệu
void inputData() {
    cout << "Nhap so tien trinh (P): ";
    cin >> P;
    cout << "Nhap so loai tai nguyen (R): ";
    cin >> R;

    maxMatrix.assign(P, vector<int>(R));
    allocation.assign(P, vector<int>(R));
    need.assign(P, vector<int>(R));
    available.resize(R);

    cout << "\nNhap MAX matrix:\n";
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            cin >> maxMatrix[i][j];

    cout << "\nNhap ALLOCATION matrix:\n";
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            cin >> allocation[i][j];

    cout << "\nNhap AVAILABLE vector:\n";
    for (int i = 0; i < R; i++)
        cin >> available[i];

    // Tính NEED = MAX - ALLOCATION
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = maxMatrix[i][j] - allocation[i][j];

    cout << "Du lieu da duoc nhap.\n";
}

// Hàm in bảng NEED
void printNeedMatrix() {
    cout << "\nBANG NEED:\n";
    for (int i = 0; i < P; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < R; j++)
            cout << setw(3) << need[i][j] << " ";
        cout << "\n";
    }
}

// Hàm kiểm tra trạng thái an toàn
bool checkSafeState() {
    vector<bool> finish(P, false);
    vector<int> work = available;
    vector<int> safeSeq;
    vector<vector<int>> workTable;

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                bool canRun = true;
                for (int j = 0; j < R; j++) {
                    if (need[i][j] > work[j]) {
                        canRun = false;
                        break;
                    }
                }

                if (canRun) {
                    for (int j = 0; j < R; j++)
                        work[j] += allocation[i][j];

                    workTable.push_back(work);
                    safeSeq.push_back(i);
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found) {
            cout << "\n❌ He thong KHONG o trang thai an toan!\n";
            return false;
        }
    }

    cout << "\n✅ He thong o trang thai an toan.\n";
    cout << "Chuoi an toan: ";
    for (int i = 0; i < safeSeq.size(); i++)
        cout << "P" << safeSeq[i] << (i == safeSeq.size() - 1 ? "\n" : " -> ");

    cout << "\nWork Table (sau moi lan cap tai nguyen):\n";
    for (const auto& row : workTable) {
        for (int val : row)
            cout << setw(3) << val << " ";
        cout << "\n";
    }

    return true;
}

// Hàm yêu cầu cấp phát tài nguyên
void requestResources() {
    int processID;
    vector<int> request(R);

    cout << "Nhap ID tien trinh yeu cau (0..." << P - 1 << "): ";
    cin >> processID;

    if (processID < 0 || processID >= P) {
        cout << "Tien trinh khong ton tai.\n";
        return;
    }

    cout << "Nhap vector yeu cau tai nguyen: ";
    for (int i = 0; i < R; i++)
        cin >> request[i];

    // Kiểm tra: Request ≤ Need
    for (int i = 0; i < R; i++) {
        if (request[i] > need[processID][i]) {
            cout << "❌ Loi: Request > Need\n";
            return;
        }
    }

    // Kiểm tra: Request ≤ Available
    for (int i = 0; i < R; i++) {
        if (request[i] > available[i]) {
            cout << "❌ Loi: Request > Available\n";
            return;
        }
    }

    // Giả sử cấp phát tạm thời
    for (int i = 0; i < R; i++) {
        available[i] -= request[i];
        allocation[processID][i] += request[i];
        need[processID][i] -= request[i];
    }

    cout << "Dang kiem tra tinh an toan...\n";
    if (checkSafeState()) {
        cout << "✅ Yeu cau duoc CHAP NHAN.\n";
    } else {
        // Rollback
        for (int i = 0; i < R; i++) {
            available[i] += request[i];
            allocation[processID][i] -= request[i];
            need[processID][i] += request[i];
        }
        cout << "❌ Yeu cau BI TU CHOI de tranh deadlock.\n";
    }
}

// Hàm main với menu
int main() {
    int choice;
    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Nhap du lieu\n";
        cout << "2. In bang NEED\n";
        cout << "3. Kiem tra trang thai an toan\n";
        cout << "4. Yeu cau cap phat tai nguyen\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputData();
                break;
            case 2:
                if (P == 0 || R == 0)
                    cout << "Vui long nhap du lieu truoc!\n";
                else
                    printNeedMatrix();
                break;
            case 3:
                if (P == 0 || R == 0)
                    cout << "Vui long nhap du lieu truoc!\n";
                else
                    checkSafeState();
                break;
            case 4:
                if (P == 0 || R == 0)
                    cout << "Vui long nhap du lieu truoc!\n";
                else
                    requestResources();
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 0);

    return 0;
}
