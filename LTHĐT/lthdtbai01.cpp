//Ho ten: Doan Minh Dai
//Ma SV: 671259
//Lop: K67CNTTA
//De:Tính diện tích và chu vi hình tam giác có 3 cạnh a,b,c. Ba cạnh a,b,c đọc vào từ tệp văn bản "tamgiac.txt". Đưa kết quả ra màn hình, đồng thời ghi ra tệp văn bản "ketqua-lthdtbai01.txt".
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>

using namespace std;
//===Khai báo hàm===

//===Chương trình chính===
int main()
{
    float a, b, c, s, p;

    ifstream fin("tamgiac.txt");
    fin >> a >> b >> c;
    fin.close();
    
    ofstream fout("ketqua-lthdtbai01.txt");
    
    if(a+b>c && a+c>b && b+c>a)
    {
        float p = (a+b+c)/2;
        float s = sqrt(p*(p-a)*(p-b)*(p-c));
        cout << "Dien tich tam giac: " << s << endl;
        cout << "Chu vi tam giac: " << a+b+c << endl;

        fout << "Dien tich tam giac: " << s << endl;
        fout << "Chu vi tam giac: " << a+b+c << endl;
    }
    else
    {
        fout << "Ba canh a, b, c khong tao thanh tam giac" << endl;
    }
    
    fout.close();
    return 0;
}
//===Định nghĩa hàm===