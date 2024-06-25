//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
/*
Cho tệp văn bản “hinhtru.txt” chứa bán kính r và chiều cao h của n hình trụ. Tính tổng 
diện tích toàn phần của n hình trụ. Đưa ra màn hình diện tích của từng hình trụ và tổng 
diện tích của n hình trụ. Biết rằng hình trụ là một loại hình tròn có bán kính r được kéo 
dài với chiều cao h. Yêu cầu sử dụng mảng động chứa n hình trụ, các hình trụ được tự 
động khởi tạo bán kính và chiều cao bằng 0
*/
#include <iostream>
#include <fstream>
using namespace std;
//Khai báo lớp đối tượng hình trụ
class HinhTron{
    private:
        float r;
    public:
        HinhTron();
        void setR(float r);
        float dienTich();
        float chuVi();
};

class HinhTru:public HinhTron{
    private:
        float h;
    public:
        HinhTru();
        void setH(float h, float r);
        float dienTichToanPhan();

};
//===Chương trình chính===
int main(){
    int n;
    float r,h,sum = 0;
    ifstream fin("hinhtru.txt");
    fin >> n;
    HinhTru *ht = new HinhTru[n];
    for (int i = 0; i < n; i++)
    {
        fin >> r >> h;
        ht[i].setH(h,r);
        cout <<"Hinh tru thu " << i+1 << " co dien tich toan phan la: " << ht[i].dienTichToanPhan() << endl;
        sum += ht[i].dienTichToanPhan();
    }
    cout << "Tong dien tich toan phan cua "<< n <<" hinh tru tren la: " << sum;
    cout << endl;
    return 0;
}
//===Khai báo hàm===
HinhTron::HinhTron():r(0){}
void HinhTron::setR(float r){
    this->r = r;
}
float HinhTron::dienTich(){
    return 3.14*r*r;
}
float HinhTron::chuVi(){
    return 2*3.14*r;
}
HinhTru::HinhTru():h(0){}
void HinhTru::setH(float h, float r){
    HinhTron::setR(r);
    this->h = h;
}
float HinhTru::dienTichToanPhan(){
    return 2*HinhTron::dienTich() + HinhTron::chuVi()*h;
}
