#include <iostream>
#include <string>

using namespace std;

struct student
{
    string name;
    int age;
    string address;
};

void addStudent(student students[], int &n)
{
    cout << "Nhap thong tin sinh vien moi:" << endl;
    cout << "Ten: ";
    cin >> students[n].name;
    cout << "Tuoi: ";
    cin >> students[n].age;
    cout << "Dia chi: ";
    cin >> students[n].address;
    n++;
}

void updateStudent(student students[], int n)
{
    string name;
    cout << "Nhap ten sinh vien can sua: ";
    cin >> name;
    for (int i = 0; i < n; i++)
    {
        if (students[i].name == name)
        {
            cout << "Nhap thong tin sinh vien moi:" << endl;
            cout << "Ten: ";
            cin >> students[i].name;
            cout << "Tuoi: ";
            cin >> students[i].age;
            cout << "Dia chi: ";
            cin >> students[i].address;
            break;
        }
    }
}

void deleteStudent(student students[], int &n)
{
    string name;
    cout << "Nhap ten sinh vien can xoa: ";
    cin >> name;
    for (int i = 0; i < n; i++)
    {
        if (students[i].name == name)
        {
            for (int j = i; j < n - 1; j++)
            {
                students[j] = students[j + 1];
            }
            n--;
            break;
        }
    }
}

void printStudents(student students[], int n)
{
    cout << endl
         << "Danh sach sinh vien:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Ten: " << students[i].name << endl;
        cout << "Tuoi: " << students[i].age << endl;
        cout << "Dia chi: " << students[i].address << endl;
        cout << endl;
    }
}

int main()
{
    student students[100];
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":" << endl;
        cout << "Ten: ";
        cin >> students[i].name;
        cout << "Tuoi: ";
        cin >> students[i].age;
        cout << "Dia chi: ";
        cin >> students[i].address;
    }
    int choice;
    while (true)
    {
        cout << endl
             << "Chuc nang:" << endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Sua thong tin sinh vien" << endl;
        cout << "3. Xoa sinh vien" << endl;
        cout << "4. In danh sach sinh vien" << endl;
        cout << "0. Thoat" << endl;
        cout << "Ban chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudent(students, n);
            break;
        case 2:
            updateStudent(students, n);
            break;
        case 3:
            deleteStudent(students, n);
            break;
        case 4:
            printStudents(students, n);
            break;
        case 0:
            return 0;
        }
    }

    return 0;
}
