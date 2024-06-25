//Họ tên: Đoàn Minh Đại
//Lớp: K67CNTTA
//MSSV: 671259
//Đề bài:
/*Cho tệp văn bản ‘sophuc.txt’ chứa phần thực và phần ảo của n số phức. Tính tổng của 
n số phức. Đưa các số phức ra màn hình ở dạng a + jb. Yêu cầu sử dụng toán tử xuất << 
để đưa số phức ra màn hình; sử dụng toán tử + để cộng hai số phức; số phức được tự 
động khởi tạo phần thực và phần ảo bằng 0; sử dụng mảng động để chứa n số phức.
*/
#include <iostream>
#include <fstream>
using namespace std;
//Khai báo lớp đối tượng so phuc
class SoPhuc{
    private:
        int thuc;
        int ao;
    public:
        SoPhuc();
        SoPhuc operator+(SoPhuc &sp2);

        //Hàm bạn
        friend ifstream& operator>> (ifstream &fin, SoPhuc &sp);
        friend ostream& operator<< (ostream &cout, SoPhuc &sp);
};
//===Chương trình chính===
int main(){
    int n,i=0;
    ifstream fin("sophuc.txt");
    fin >> n;
    SoPhuc *sp = new SoPhuc[n];
    SoPhuc sum;
    while (fin >> sp[i])
    {
        cout <<"So phuc thu " << i+1 << ": " << sp[i] << endl;
        sum = sum + sp[i];
        i++;
    }
    cout << "Tong cua "<< n <<" so phuc tren la: " << sum;
    cout << endl;
    return 0;
}
//===Khai báo hàm===
SoPhuc::SoPhuc():thuc(0), ao(0){}
SoPhuc SoPhuc::operator+(SoPhuc &sp2){
    SoPhuc temp;
    temp.thuc = thuc + sp2.thuc;
    temp.ao = ao + sp2.ao;
    return temp;
}
ifstream& operator>>(ifstream &fin, SoPhuc &sp){
    fin >> sp.thuc >> sp.ao;
    return fin;
}
ostream& operator<<(ostream &cout, SoPhuc &sp){
    if(sp.ao>=0) cout<<sp.thuc<<" + j"<<sp.ao;
    else cout<<sp.thuc<<" - j"<<-sp.ao;
    return cout;
}