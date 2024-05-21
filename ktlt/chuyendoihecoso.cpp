#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <cstring>

using namespace std;

// hàm chuyển đổi từ hệ thập phân sang hệ nhị phân
string thapphan_nhiphan(int number)
{
    string s = ""; //Tạo xâu S để lưu giá trị xâu nhị phân sau khi chuyển đổi
    while (number != 0)
    {
        if (number % 2 == 1)
        {
            s = "1" + s;
        }
        else
        {
            s = "0" + s;
        }
        number = number / 2;
    }
    return s;
}

// hàm chuyển đổi từ hệ thập phân sang hệ thập lục phân
string thapphan_thaplucphan(int number)
{
    string s = ""; //Tạo xâu S để lưu giá trị xâu thập lục phân sau khi chuyển đổi
    while (number != 0)
    {
        if (number % 16 < 10)
        {
            s = char(number % 16 + 48) + s; //Phần dư nhỏ hơn 10 nối phần dư vào xâu
        }
        else
        {
            s = char(number % 16 + 55) + s; //Phần dư lớn hơn 10 chuyển phần dư thành chứ in hoa bằng cách + 55 để lấy giá trị kí tự chữ hoa trong bảng mã askey
        }
        number = number / 16;
    }
    return s;
}

// hàm chuyển đổi các hệ sang hệ thập phân, nhập vào chuỗi và hệ số chuyển đổi
int chuyendoisanghethapphan(string number, int hesochuyendoi)
{
    int soThapPhan = 0;
    int soMu = 0;
    for (int i = number.length() - 1; i >= 0; i--)
    {
        char kytu = number[i];
        int giatrikytu;
        if (kytu >= '0' && kytu <= '9')
        {
            giatrikytu = kytu - '0';
        }
        else if (kytu >= 'A' && kytu <= 'F')
        {
            giatrikytu = kytu - 'A' + 10;
        }
        else if (kytu >= 'a' && kytu <= 'f')
        {
            giatrikytu = kytu - 'a' + 10;
        }
        else
        {
            return -1;
        }

        soThapPhan += giatrikytu * pow(hesochuyendoi, soMu);
        soMu++;
    }
    return soThapPhan;
}

// Hàm chuyển đổ từ số nguyên có dấu sang hệ nhị phân
int songuyencodau(string number)
{
    int soThapPhan = -(number[0] - '0') * pow(2, number.length() - 1);
    for (int i = number.length() - 1; i > 0; i--)
    {
        int giatrikytu = number[i] - '0';
        soThapPhan += giatrikytu * pow(2, number.length() - 1 - i);
    }
    return soThapPhan;
}

// Hàm chuyển đổi từ nhị phân sang số nguyên có dấu
string nhiphancodau(int number)
{
    string nhiphan = bitset<8>(number).to_string();
    size_t pos = nhiphan.find_first_not_of('0');
    if (pos != string::npos)
        nhiphan = nhiphan.substr(pos);
    else
        nhiphan = "0";
    return nhiphan;
}

// Hàm chuyển đổi từ nhị phân sang số thực
float nhiphan_sothuc(string nhiphan)
{
    if (nhiphan.length() != 32)
    {
        cout << "Invalid nhiphan string" << endl;
        return 0.0;
    }

    // Kiểm tra bit dấu là bit đầu tiên và tách ra
    int dau = (nhiphan[0] == '1') ? -1 : 1;

    // Tách bit số mũ và tính giá trị của mũ
    string xauSoMu = nhiphan.substr(1, 8);
    int giaTriSoMu = bitset<8>(xauSoMu).to_ulong() - 127;

    // Tách bit giá trị số thực và tính toán
    string xauSoThuc = nhiphan.substr(9);
    float giaTriSoThuc = 1.0;
    for (int i = 0; i < xauSoThuc.length(); i++)
    {
        if (xauSoThuc[i] == '1')
        {
            giaTriSoThuc += pow(2.0, -(i + 1));
        }
    }

    // Tính giá trị số thực
    float giaTri = dau * giaTriSoThuc * pow(2.0, giaTriSoMu);
    return giaTri;
}

// Hàm chuyển dổi từ số thực sang hệ nhị phân
string sothuc_nhiphan(float number)
{
    union
    {
        float f;
        uint32_t i;
    } u;
    u.f = number;
    bitset<32> bits(u.i);
    string nhiphan = bits.to_string();

    int e = 127;
    if (number == 0.0)
    {
        nhiphan = "00000000000000000000000000000000";
    }
    else if (number < 0)
    {
        nhiphan[0] = '1';
    }

    if (number != 0)
    {
        float fraction = abs(number);
        while (fraction >= 2.0)
        {
            e++;
            fraction /= 2.0;
        }
        while (fraction < 1.0 && e > 0)
        {
            e--;
            fraction *= 2.0;
        }
        fraction -= 1.0;
        string fractionnhiphan;
        for (int i = 0; i < 23; i++)
        {
            fraction *= 2.0;
            if (fraction >= 1.0)
            {
                fractionnhiphan += '1';
                fraction -= 1.0;
            }
            else
            {
                fractionnhiphan += '0';
            }
        }
        bitset<8> exponent(e);
        nhiphan.replace(1, 8, exponent.to_string());
        nhiphan.replace(9, 23, fractionnhiphan);
    }
    return nhiphan;
}

int main()
{
    int choice;
    int number = 0;
    float num;
    string s;
    while (1)
    {
        cout << "1.Chuyen tu he thap phan sang nhi phan.\n2.Chuyen tu he thap phan sang thap luc phan.\n3.Chuyen tu he nhi phan sang thap phan.\n4.Chuyen doi tu he nhi phan sang thap luc phan.\n5.Chuyen tu he thap luc phan sang thap phan.\n6.Chuyen tu he thap luc phan sang nhi phan.\n7.Chuyen he nhi phan sang so nguyen co dau.\n8.Chuyen tu so nguyen co dau sang chuoi nhi phan.\n9.Chuyen tu chuoi nhi phan thanh so thuc.\n10.Chuyen tu so thuc ve chuoi nhi phan.\n11.Thoat.\n\nChon de thuc hien: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n\nNhap vao so can chuyen doi: ";
            cin >> number;

            cout << "So da nhap chuyen sang he nhi phan la: " << thapphan_nhiphan(number) << endl;

            cin.ignore(1, '\n');
            getchar();

            system("cls");

            break;

        case 2:
            cout << "\n\nNhap vao so can chuyen doi: ";
            cin >> number;

            cout << "So da nhap chuyen sang he thap luc phan la: " << thapphan_thaplucphan(number) << endl;

            cin.ignore(1, '\n');
            getchar();

            system("cls");

            break;

        case 3:
            cout << "\n\nNhap vao so can chuyen doi: ";
            cin >> s;

            cout << "So da nhap chuyen sang he thap phan la: " << chuyendoisanghethapphan(s, 2) << endl;

            cin.ignore(1, '\n');
            getchar();

            system("cls");

            break;

        case 4:
            cout << "\n\nNhap vao so can chuyen doi: ";
            cin >> s;

            number = chuyendoisanghethapphan(s, 2);

            cout << "So da nhap chuyen sang he thap luc phan la: " << thapphan_thaplucphan(number) << endl;

            cin.ignore(1, '\n');
            getchar();

            system("cls");

            break;

        case 5:
            cout << "\n\nNhap vao so can chuyen doi: ";
            cin >> s;

            cout << "So da nhap chuyen sang he thap phan la: " << chuyendoisanghethapphan(s, 16) << endl;

            cin.ignore(1, '\n');
            getchar();

            system("cls");

            break;

        case 6:
            cout << "\n\nNhap vao so can chuyen doi: ";
            cin >> s;

            number = chuyendoisanghethapphan(s, 16);

            cout << "So da nhap chuyen sang he thap luc phan la: " << thapphan_nhiphan(number) << endl;

            cin.ignore(1, '\n');
            getchar();

            system("cls");

            break;

        case 7:
            cout << "\n\nNhap vao so can chuyen doi: ";
            cin >> s;

            cout << "So nhi phan da nhap chuyen thanh so nguyen co dau la: " << songuyencodau(s) << endl;

            cin.ignore(1, '\n');
            getchar();

            system("cls");

            break;

        case 8:
            int sobit;
            cout << "\n\nNhap vao so can chuyen doi(-128 den 127): ";
            cin >> number;

            cout << "So nhi phan da nhap chuyen thanh so nguyen co dau la: " << nhiphancodau(number) << endl;

            cin.ignore(1, '\n');
            getchar();

            system("cls");

            break;

        case 9:
            cout << "\n\nNhap vao chuoi can chuyen doi: ";
            cin >> s;

            cout << "Chuoi nhi phan da nhap o dang so thuc la: " << nhiphan_sothuc(s) << endl;

            cin.ignore(1, '\n');
            getchar();

            system("cls");

            break;

        case 10:
            cout << "\n\nNhap vao so thuc chuyen doi: ";
            cin >> num;

            cout << "So thuc da nhap co dang chuoi nhi phan la: " << sothuc_nhiphan(num) << endl;

            cin.ignore(1, '\n');
            getchar();

            system("cls");
        case 11:
            return 0;

        default:
            break;
        }
    }
    return 0;
}