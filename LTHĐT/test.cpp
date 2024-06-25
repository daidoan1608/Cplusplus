#include<iostream>
#include<cstring>


class MatHang {
private:
    char *tenHang;  // Assuming the max length is 50
    int soLuong;
    float donGia;

public:
    MatHang();  // No-argument constructor
    MatHang(char* tenHang, int soLuong, float donGia);  // Parameterized constructor
    void nhap();  // A member function to input data
    void xuat();  // A member function to display data (optional)
};

// Definition of no-argument constructor
MatHang::MatHang() : soLuong(0), donGia(0), tenHang(""){
}

// Definition of parameterized constructor
MatHang::MatHang(char* tenHang, int soLuong, float donGia) : tenHang(tenHang), soLuong(soLuong), donGia(donGia) {  // Initialize tenHang using the provided string
}

// Definition of nhap() function
void MatHang::nhap() {
    std::cout << "Nhap vao ten mat hang: ";
    std::cin.ignore();  // Ignore any remaining characters in the input buffer
    std::cin.getline(tenHang, 50);  // Read up to 50 characters into tenHang
    std::cout << "Nhap vao so luong: ";
    std::cin >> soLuong;
    std::cout << "Nhap vao don gia: ";
    std::cin >> donGia;
}

// Definition of xuat() function (optional, for displaying data)
void MatHang::xuat() {
    std::cout << "Ten mat hang: " << tenHang << std::endl;
    std::cout << "So luong: " << soLuong << std::endl;
    std::cout << "Don gia: " << donGia << std::endl;
}

int main() {
    MatHang mh1;  // Create an object using the no-argument constructor
    mh1.nhap();   // Input data
    mh1.xuat();   // Display data

    MatHang mh2("Example", 10, 25.5);  // Create an object using the parameterized constructor
    mh2.xuat();   // Display data

    return 0;
}
