//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
// Thời gian có giờ và phút, giờ có giá trị trong khoảng 0-23, phút có giá trị trong khoảng 
// 0-59. Nhập vào thời gian bắt đầu một ca thi và số phút làm bài thi. Tính thời gian kết 
// thúc ca thi. Yêu cầu sử dụng toán tử nhập >> và toán tử xuất << để nhập vào và đưa ra 
// thời gian ở dạng h:mm, sử dụng toán tử + để cộng thời gian với số phút, thời gian được 
// khởi tạo tự động với giờ và phút bằng 0 hoặc khởi tạo bằng giờ, phút cho trước.
#include <iostream>
using namespace std;
//Khai báo lớp đối tượng thời gian
class Time{
    private:
        int hour;
        int minute;
    public:
        Time();
        Time(int h, int m);
        Time operator+(int m);

        //Hàm bạn
        friend istream& operator>> (istream &cin, Time &t);
        friend ostream& operator<< (ostream &cout, Time &t);
};
//===Chương trình chính===
int main(){
    Time start, end;
    int duration;
    cout << "Nhap thoi gian bat dau: " << endl;
    cin >> start;
    cout << "Nhap thoi gian lam bai: "; cin >> duration;
    end = start + duration;
    cout << "Thoi gian ket thuc: " << end;
    cout << endl;
    return 0;
}
//===Khai báo hàm===
Time::Time():hour(0), minute(0){}
Time::Time(int h, int m):hour(h), minute(m){}
Time Time::operator+(int m){
    Time temp;
    temp.hour = hour;
    temp.minute = minute + m;
    if(temp.minute >= 60){
        temp.hour += temp.minute / 60;
        temp.minute %= 60;
    }
    if (temp.hour >= 24)
    {
        temp.hour %= 24;
    }
    
    return temp;
}
istream& operator>>(istream &cin, Time &t){
    cout << "Nhap gio: "; cin >> t.hour;
    cout << "\nNhap phut: "; cin >> t.minute;
    return cin;
}
ostream& operator<<(ostream &cout, Time &t){
    cout << t.hour << ":" << t.minute;
    return cout;
}