#include <iostream>
#include <vector>

using namespace std;

// Cấu trúc Sinh viên
struct Student {
    string id, name;
    int birthYear;
    double gpa;
};

void printStudents(const vector<Student>& students) {
    cout << "-------\n";
    for (const auto& s : students) {
        cout << s.id << " | " << s.name << " | " << s.birthYear << " | GPA: " << s.gpa << endl;
    }
    cout << "-------\n";
}

void insertionSort(vector<Student>& students) {
    for (size_t i = 1; i < students.size(); i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].gpa > key.gpa) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

void bubbleSort(vector<Student>& students) {
    for (size_t i = 0; i < students.size() - 1; i++) {
        for (size_t j = 0; j < students.size() - i - 1; j++) {
            if (students[j].gpa > students[j + 1].gpa) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void heapify(vector<Student>& students, int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && students[left].gpa > students[largest].gpa) largest = left;
    if (right < n && students[right].gpa > students[largest].gpa) largest = right;
    if (largest != i) {
        swap(students[i], students[largest]);
        heapify(students, n, largest);
    }
}

void heapSort(vector<Student>& students) {
    int n = students.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(students, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(students[0], students[i]);
        heapify(students, i, 0);
    }
}

int main() {
    vector<Student> students = {
        {"SV01", "Nguyen Van Cuong", 2002, 3.2},
        {"SV02", "Tran Thi Ngoc Anh", 2001, 2.9},
        {"SV03", "Le Huu Trac", 2000, 3.8},
        {"SV04", "Pham Thi Tuyet Nhi", 2002, 3.5},
        {"SV05", "Hinh Khac Luy", 2003, 2.7}
    };

    while (true) {
        cout << "\nDanh sach sinh vien hien tai:\n";
        printStudents(students);

        cout << "\nChon thuat toan sap xep:\n";
        cout << "1. Sap xep chen (Insertion Sort)\n";
        cout << "2. Sap xep noi bot (Bubble Sort)\n";
        cout << "3. Sap xep vun dong (Heap Sort)\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        
        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "Thoat chuong trinh!\n";
            break;
        }
        vector<Student> sortedStudents = students;

        switch (choice) {
            case 1:
                insertionSort(sortedStudents);
                cout << "\nDanh sach sau khi sap xep chen:\n";
                break;
            case 2:
                bubbleSort(sortedStudents);
                cout << "\nDanh sach sau khi sap xep noi bot:\n";
                break;
            case 3:
                heapSort(sortedStudents);
cout << "\nDanh sach sau khi sap xep vun dong:\n";
                break;
            default:
                cout << "Lua chon khong hop le! Vui long chon lai.\n";
                continue;
        }

        printStudents(sortedStudents);
    }

    return 0;
}