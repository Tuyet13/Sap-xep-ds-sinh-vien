#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

struct Student {
    std::string id;
    std::string name;
    int birthYear;
    float gpa;
};

void printStudents(const std::vector<Student>& students) {
    for (const auto& student : students) {
        std::cout << student.id << ", " << student.name << ", " << student.birthYear << ", " << student.gpa << std::endl;
    }
}

std::vector<Student> readStudentsFromFile(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Student student;
        if (iss >> student.id >> student.name >> student.birthYear >> student.gpa) {
            students.push_back(student);
        }
    }
    return students;
}

void insertionSort(std::vector<Student>& students) {
    for (size_t i = 1; i < students.size(); ++i) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].gpa > key.gpa) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
    }
}

void bubbleSort(std::vector<Student>& students) {
    for (size_t i = 0; i < students.size() - 1; ++i) {
        for (size_t j = 0; j < students.size() - i - 1; ++j) {
            if (students[j].gpa > students[j + 1].gpa) {
                std::swap(students[j], students[j + 1]);
            }
        }
    }
}

void heapify(std::vector<Student>& students, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && students[left].gpa > students[largest].gpa)
        largest = left;
    if (right < n && students[right].gpa > students[largest].gpa)
        largest = right;
    if (largest != i) {
        std::swap(students[i], students[largest]);
        heapify(students, n, largest);
    }
}

void heapSort(std::vector<Student>& students) {
    int n = students.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(students, n, i);
    for (int i = n - 1; i >= 0; i--) {
        std::swap(students[0], students[i]);
        heapify(students, i, 0);
    }
}

int main() {
    std::string filename = "students.txt";
    std::vector<Student> students = readStudentsFromFile(filename);

    std::cout << "Danh sach sinh vien truoc khi sap xep:\n";
    printStudents(students);

    // Chon giai thuat sap xep tai day
    insertionSort(students);
    // bubbleSort(students);
    // heapSort(students);

    std::cout << "\nDanh sach sinh vien sau khi sap xep:\n";
    printStudents(students);

    return 0;
}

