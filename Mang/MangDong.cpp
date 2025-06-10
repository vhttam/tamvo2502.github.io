/*
Họ tên: Võ Huỳnh Thanh Tâm
MSSV: 3124411267
Lớp: DCT124C7
*/
#include <iostream>
#include <cstdio>
#define TS "test.txt"
#define OUT "output.txt"
using namespace std;
//Hàm viết vào file test.txt
void writefile (int &n,int &m,int** &a){
    FILE *file=fopen(TS,"wt");
    //Nếu file không có thì dừng
    if (file==NULL){
        return;
    }
    //Nhập số dòng m
    cout<<"Moi nhap so dong m: ";
    cin>>m;
    //Nhập số lượng phần tử của mỗi dòng n
    cout<<"Moi nhap so luong phan tu n: ";
    cin>>n;
    //Ghi vào file
    fprintf(file,"%d %d\n",m,n);
    //Cấp phát bộ nhớ động
    a=new int*[m];
    for (int i=0;i<m;i++){
        a[i]=new int[n];
    }
    //Nhập các phần tử vào mảng a
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout<<"["<<i<<"]["<<j<<"]= ";
            cin>>a[i][j];
            cout<<" ";
            //Lưu các phần tử vào file
            fprintf(file,"%d ",a[i][j]);
        }
        //Xuống dòng khi số lượng phần tử đạt yêu cầu
        fprintf(file,"\n");
    }
    //Đóng file
    fclose(file);
}
//Hàm đọc file test.txt
void readfile(int &n,int &m,int** &a){
    FILE* file=fopen(TS,"rt");
    //Nếu file không tồn tại thì dừng
    if (file==NULL){
        return;
    }
    //Xuất ra màn hình số dòng m và số lượng phần tử n
    fscanf(file,"%d %d",&m,&n);
    //Cấp phát bộ nhớ động cho a
    a=new int*[m];
    for (int i=0;i<m;i++){
        a[i]=new int[n];
    }
    //Xuất ra màn hình mảng a
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            fscanf(file,"%d ",&a[i][j]);
        }
        fscanf(file,"\n");
    }
    //Đóng file
    fclose(file);
}
//Hàm tìm phần tử lớn nhất và lớn nhì
void MAX1_MAX2(int** a,int m,int n,FILE* file){
    int MAX1=a[0][0];
    int MAX2=INT_MIN;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            int Index=a[i][j];
            if (MAX1<Index){
                //Nếu MAX<Index thì MAX2= MAX1, MAX1=Index
                MAX2=MAX1;
                MAX1=Index;
            }
            //Nếu MAX1>Index mà MAX2<Index thì MAX2=Index
            else if ((MAX2<Index&&Index!=MAX1)){
                MAX2=Index;
            }
        }
    }
    //Nếu xét hết mà không có phần tử lớn thứ 2
    if (MAX2==INT_MIN){
        fprintf(file,"Khong tim thay phan tu lon thu 2 trong mang\n");
        //In ra màn hình MAX1
        cout<<MAX1;
        //Ghi vào file MAX1
        fprintf(file,"%d",MAX1);
        return;
    }
    //In ra màn hình MAX1 và MAX2
    cout<<MAX1<<" "<<MAX2<<endl;
    //Ghi vào file MAX1 và MAX2
    fprintf(file,"%d %d",MAX1,MAX2);
    fprintf(file,"\n");
}
//Hàm tính tổng
void TinhTong (int** a,int m,int n,FILE* file){
    for (int j=0;j<n;j++){
        //Cho S=0 mỗi khi tính xong 1 cột
        int S = 0;
        //Cho i chạy từ hàng 1 đến hàng m-1
        for (int i=0;i<m;i++){
            //Tính tổng của mỗi cột
            S+=a[i][j];
        }
        //Ghi ra màn hình và lưu vào file
        cout<<"Tong cac phan tu cua cot "<<j+1<<" la: "<<S<<endl;
        fprintf(file,"%d ",S);
    }
}
//Hàm tạo mảng C=a[i][j]*kj với kj là phần tử nhỏ nhất trong hàng
void Mang_C(int** a,int m,int n,int** &c,FILE* file){
    int MIN=a[0][0];
    //Tạo mảng b chứa các phần tử nhỏ nhất mỗi hàng
    int*  b;
    b=new int[m];
    for (int i=0;i<m;i++){
        //MIN= phần tử đầu tiên của mỗi hàng
        MIN=a[i][0];
        for (int j=0;j<n;j++){
            int Index=a[i][j];
            if (Index<MIN){
                //Tìm MIN trong hàng
                MIN=Index;
            }
        }
        //Lưu MIN vào b mỗi khi kết thúc vòng lặp j
        b[i]=MIN;
    }
    //Tạo mảng động c và cấp phát vùng nhớ
    c=new int*[m];
    for (int i=0;i<m;i++){
        c[i]=new int[n];
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            //Tính toán các phần tử và lưu vào c[i][j]
            c[i][j]=b[i]*a[i][j];
            cout<<" "<<c[i][j];
            //Lưu vào file
            fprintf(file,"%d ",c[i][j]);
        }
        //Xuống dòng mỗi khi kết thúc 1 hàng
        cout<<"\n";
        //Lưu vào file
        fprintf(file,"\n");
    }
    //Giải phòng vùng nhớ b
    delete[] b;
}
//Hàm main
int main(){
    int n,m;
    int **a,**c;
    //Ghi kết quả vào file output.txt
    FILE* file = fopen(OUT, "wt");
    //Hàm ghi
    writefile(n,m,a);
    //Hàm đọc
    readfile(n,m,a);
    //Hàm tìm MAX1 MAX2
    MAX1_MAX2(a,m,n,file);
    //Hàm tính tổng
    TinhTong (a,m,n,file);
    //Trình bày và ghi vào file mảng c
    fprintf(file,"\n");
    cout<<"Mang C:\n";
    fprintf(file,"Mang C:\n");
    Mang_C(a,m,n,c,file);
    //Giải phóng vùng nhớ a và c
    for (int i = 0; i < m; i++) {
        delete[] a[i];
        delete[] c[i];
    }
    delete[] c;
    delete[] a;
    fclose(file);
    return 0;
}
