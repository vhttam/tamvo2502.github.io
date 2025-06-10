// khai báo thư viện
#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>
using namespace std;
// khởi tạo danh sách câu hỏi và câu trả lời, đáp án
struct Danhsach
{
    // Danh sách câu hỏi
    string question[10]={
    "1 + 1 = ?",
    "League of Legend có bao nhiêu vị tướng?",
    "Kiểu dữ liệu char là kiểu gì?",
    "1,2,3,5 anh có đánh rơi nhịp nào không?",
    "1000 - 7 = ?",
    "Một ngày kim giờ bao nhiêu vòng?",
    "Fe + HCl -> ?",
    "Vua Quang Trung và Nguyễn Huệ có quan hệ gì?",
    "Tại sao xì trum màu xanh?",
    "Bạn nghĩ mình bao nhiêu điểm?"
    };
    // Danh sách các đáp án
    string answer[10][4]={
    {"a.5","b.1","c.2","d.11"},
    {"a.150","b.175","c.200","d.125"},
    {"a.kí tự","b.số nguyên","c.số thực","d.Logic"},
    {"a.có,6","b.có,7","c.có,4","d.không"},
    {"a.993","b.990","c.1007","d.7"},
    {"a.1","b.2","c.3","d.24"},
    {"a.FeCl2","b.FeCl3","c.Fe2Cl","d.Fe3Cl"},
    {"a.anh em","b.sư đồ","c.siuuuuuuuuu","d.là một"},
    {"a.Vì mắt mình bị mù màu","b.Vì nó làm đổ sơn lên người","c.Vì tự nhiên nó vậy","d.Vì hết màu khác"},
    {"a.1","b.2","c.10","d.5"}
    };
    // Danh sách đáp án đúng của từng câu
    char Correct_Answer[10]={
        'c','b','a','c','a','b','a','d','c','c'
    };
    char Your_Answer[10];
    char Your_Answer1[10];
};
  Danhsach Ds;
  int Diem = 0;
  int So_Cau_Dung = 0,So_Cau_Sai = 0;
  int Retry[10]={0};
  // In ra danh sách câu hỏi và câu trả lời
  void DisplayQuestion ( Danhsach &ds, int i)
  {
    cout << Ds.question[i] << endl;
    for (int j = 0; j < 4; j++)
    cout << Ds.answer[i][j] << endl;
    for (int t = 0; t < 1; t++)
    {
        cout << "Mời nhập câu trả lời của bạn:";
        cin>>Ds.Your_Answer[i];
    }
  // chuyển đổi hoa --> thường
 for (int i = 0;i < 10;i++)
    (Ds.Your_Answer1[i]) =std::tolower(Ds.Your_Answer[i]);
  }
// Chế độ luyện tập
void training ( Danhsach &ds) 
{
    cout <<" Chế độ luyện tập\n";
    for (int i = 0; i < 10; i++)
    {
   DisplayQuestion(ds, i);
    while (Ds.Your_Answer1[i] != Ds.Correct_Answer[i])
   {
    Retry[i]+=1;
    cout << "Vui lòng trả lời lại:";
    cin >> Ds.Your_Answer[i];
     for (int i = 0;i < 10;i++)
    (Ds.Your_Answer1[i]) =std::tolower(Ds.Your_Answer[i]);
   }
    cout<<"Chúc mừng bạn đã trả lời đúng\n";
    }
    for (int i = 0; i < 10; i++)
    {
    cout<<"Số lần trả lời sai câu "<<i+1<<": "<<Retry[i]<<endl;
    cout<<"Danh sách câu hỏi:"<<endl;
    cout<<Ds.question[i]<<endl;
    }
}
// Chế độ kiểm tra
void test ( Danhsach &ds) 
{
    cout << "Chế độ kiểm tra\n";
    for (int i = 0; i < 10; i++)
    {
   DisplayQuestion(ds, i);
    if (Ds.Your_Answer1[i] == Ds.Correct_Answer[i] )
        {
             Diem+= 1;
        }
        // Tính số câu đúng
    if (Ds.Your_Answer1[i] == Ds.Correct_Answer[i] )
        {
            So_Cau_Dung+= 1;
        }
        //Tính số câu sai
            So_Cau_Sai = 10 - So_Cau_Dung;
    }
        // Tính điểm
        cout<<"Điểm:"<<Diem<<"/10"<<endl;
        cout<<"Số câu sai:"<<So_Cau_Sai<<endl;
        cout<<"Số câu đúng:"<<So_Cau_Dung<<endl;
}
int main()
{
    // Khai báo
    int mode;
// Chọn chế độ
cout << "Hãy chọn chế độ:\n 1.Luyện tập\n 2. Kiểm tra";
cin >> mode;
if (mode == 1)
{
   training(Ds);
}
else if (mode == 2)
{
   test(Ds);
}
else if ((mode != 1)||(mode !=2))
{
    cout<<"Vui lòng nhấp số 1 hoặc 2"<<endl;
    return 0;
}
return 0;
}
