#include <iostream>
#define MAX 1000
using namespace std;

struct Process {
    int P;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    bool is_completed=false;
    int remaining_time;
};

// Sắp xếp theo thời gian đến
void sortByArrival(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                swap(p[i], p[j]);
            }
        }
    }
}

void FIFO () {
    Process processes[MAX];
    int n;

    cout << "Nhap so luong tien trinh: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        processes[i].P = i + 1;
        cout << "Tien trinh " << processes[i].P << ":\n";
        cout << " - Nhap thoi gian den: ";
        cin >> processes[i].arrival_time;
        cout << " - Nhap thoi gian thuc hien: ";
        cin >> processes[i].burst_time;
    }

    sortByArrival(processes, n);

    // Tính toán thời gian bắt đầu, kết thúc, chờ, hoàn thành
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            processes[i].start_time = processes[i].arrival_time;
        } else {
            processes[i].start_time = max(processes[i - 1].completion_time, processes[i].arrival_time);
        }

        processes[i].completion_time = processes[i].start_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    // In kết quả ra màn hình
    cout << "\nKet qua lap lich theo FIFO:\n";
    cout << "TienTrinh\tDen\tThucHien\tBatDau\tThoiGianLuuLaiTrenHeThong\tCho\tHoanThanh\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].P << "\t\t"
             << processes[i].arrival_time << "\t"
             << processes[i].burst_time << "\t\t"
             << processes[i].start_time << "\t"
             << processes[i].turnaround_time << "\t\t\t\t"
             << processes[i].waiting_time << "\t"
             << processes[i].completion_time << "\n";
    }
}

void SJF ()
{
    Process processes[MAX];
    int n;

    cout << "Nhap so luong tien trinh: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        processes[i].P = i + 1;
        cout << "Tien trinh " << processes[i].P << ":\n";
        cout << " - Nhap thoi gian den: ";
        cin >> processes[i].arrival_time;
        cout << " - Nhap thoi gian thuc hien: ";
        cin >> processes[i].burst_time;
    }
        sortByArrival(processes, n);
        int completed=0;
        int current_time=0;
      // Tính toán thời gian bắt đầu, kết thúc, chờ, hoàn thành
    while (completed<n) {
        int idx = -1;
        int min_burst = INT_MAX;
        //Tìm tiến trình có burst nhỏ nhất chưa hoàn thành và đã vào hàng đợi
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && !processes[i].is_completed) {
                if (processes[i].burst_time < min_burst) {
                    min_burst = processes[i].burst_time;
                    //Đưa idx đến vị trí tiến trình đó
                    idx = i;
                }
            }
        }
        //Tính toán thời gian bắt đầu, hoàn thành, kết thúc,đợi và đổi is_complete của tiến trình đó thành true
        if (idx != -1) {
            processes[idx].start_time = current_time;
            processes[idx].completion_time = processes[idx].start_time + processes[idx].burst_time;
            processes[idx].turnaround_time = processes[idx].completion_time - processes[idx].arrival_time;
            processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;
            processes[idx].is_completed = true;

            current_time = processes[idx].completion_time;
            completed++;
        } else {
            current_time++; // Không có tiến trình nào đã đến => CPU chờ
        }
    }

    // In kết quả
    cout << "\nKet qua lap lich theo SJF:\n";
    cout << "TienTrinh\tDen\tThucHien\tBatDau\tThoiGianLuuLaiTrongHeThong\tCho\tHoanThanh\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].P << "\t\t"
             << processes[i].arrival_time << "\t"
             << processes[i].burst_time << "\t\t"
             << processes[i].start_time << "\t"
             << processes[i].turnaround_time << "\t\t\t\t"
             << processes[i].waiting_time << "\t"
             << processes[i].completion_time << "\n";
    }
}

void SRTF() {
    Process processes[MAX];
    int n;

    cout << "Nhap so luong tien trinh: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        processes[i].P = i + 1;
        cout << "Tien trinh " << processes[i].P << ":\n";
        cout << " - Nhap thoi gian den: ";
        cin >> processes[i].arrival_time;
        cout << " - Nhap thoi gian thuc hien: ";
        cin >> processes[i].burst_time;
        processes[i].remaining_time=processes[i].burst_time;
    }
        sortByArrival(processes, n);
        int completed=0;
        int current_time=0;
    // Tính toán thời gian bắt đầu, kết thúc, chờ, hoàn thành
    while (completed<n) {
        int idx = -1;
        int min_burst = INT_MAX;
        //Tìm tiến trình có burst nhỏ nhất chưa hoàn thành và đã vào hàng đợi
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && !processes[i].is_completed) {
                if (processes[i].burst_time < min_burst) {
                    min_burst = processes[i].burst_time;
                    //Đưa idx đến vị trí tiến trình đó
                    idx = i;
                }
            }
        }
        if (idx != -1){
            if(processes[idx].remaining_time==processes[idx].burst_time){
                processes[idx].start_time=current_time;
            }
            current_time++;
            processes[idx].remaining_time--;
            if(processes[idx].remaining_time==0){
                processes[idx].completion_time = current_time;
                processes[idx].turnaround_time = processes[idx].completion_time - processes[idx].arrival_time;
                processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;
                processes[idx].is_completed = true;
                completed++;
            }
        }
        else
        current_time++;
    }

    // In kết quả
    cout << "\nKet qua lap lich theo SRTF:\n";
    cout << "TienTrinh\tDen\tThucHien\tBatDau\tThoiGianLuuLaiTrongHeThong\tCho\tHoanThanh\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].P << "\t\t"
             << processes[i].arrival_time << "\t"
             << processes[i].burst_time << "\t\t"
             << processes[i].start_time << "\t"
             << processes[i].turnaround_time << "\t\t\t\t"
             << processes[i].waiting_time << "\t"
             << processes[i].completion_time << "\n";
    }
}

void RR(){
    Process processes[MAX];
    int n;
    int quantum;
    cout << "Nhap so luong tien trinh: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        processes[i].P = i + 1;
        cout << "Tien trinh " << processes[i].P << ":\n";
        cout << " - Nhap thoi gian den: ";
        cin >> processes[i].arrival_time;
        cout << " - Nhap thoi gian thuc hien: ";
        cin >> processes[i].burst_time;
        processes[i].remaining_time=processes[i].burst_time;
    }
    sortByArrival(processes, n);
    cout << "Nhap quantum: ";
    cin >> quantum;
    int completed =0;
    int current_time=0;
    while(completed<n){
        bool executedInThisCycle =false;
        for (int i=0;i<n;i++){
            if (processes[i].arrival_time<=current_time && !processes[i].is_completed) {
                executedInThisCycle= true;
                if (processes[i].remaining_time<=quantum){
                    current_time=current_time+processes[i].remaining_time;
                    processes[i].remaining_time=0;
                    processes[i].completion_time= current_time;
                    processes[i].turnaround_time= processes[i].completion_time-processes[i].arrival_time;
                    processes[i].waiting_time= processes[i].turnaround_time-processes[i].burst_time;
                    processes[i].is_completed=true;
                    completed++;
                }
                else {
                processes[i].remaining_time=processes[i].remaining_time-quantum;
                current_time=current_time+quantum;
                }
            }
        }
        if (!executedInThisCycle)
        current_time++;
    }

    // In kết quả
    cout << "\nKet qua lap lich theo RR:\n";
    cout << "TienTrinh\tDen\tThucHien\tBatDau\tThoiGianLuuLaiTrongHeThong\tCho\tHoanThanh\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << processes[i].P << "\t\t"
             << processes[i].arrival_time << "\t"
             << processes[i].burst_time << "\t\t"
             << processes[i].start_time << "\t"
             << processes[i].turnaround_time << "\t\t\t\t"
             << processes[i].waiting_time << "\t"
             << processes[i].completion_time << "\n";
    }
}

int main() {
    FIFO();
    SJF();
    SRTF();
    RR();
    return 0;
}
