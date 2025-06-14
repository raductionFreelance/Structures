#include <iostream>
#include <string>
using namespace std;

struct Student{
    string surname;
    int group;
    int marks[5];
};

Student* IncreaseNumber(Student* students, int& n, int n2){
    Student* new_students = new Student[n2];
    for (int i=0; i<n; i++){
        new_students[i]=students[i];
    }
    delete[] students;
    return new_students;
}

void print1(Student* students, int n){
    for (int i=0; i<n; i++){
        int k=0;
        for (int mark:students[i].marks){
            if (mark>=10){
                k++;
            }
        }
        if (k/5.0>=0.75){
            cout << students[i].surname << endl;
        }
    }
}
void print2(Student* students, int n){
    for (int i=0; i<n; i++){
        int k=0;
        for (int mark:students[i].marks){
            if (mark==2 || mark==3){
                k++;
            }
        }
        if (k/5.0>=0.5){
            cout << students[i].surname << endl;
        }
    }
}

int main() {
    int n = 5;
    Student* students = new Student[n]{
        {"Іваненко", 101, {10, 11, 12, 10, 9}},
        {"Петренко", 102, {3, 2, 10, 11, 2}},
        {"Сидоренко", 103, {9, 9, 8, 9, 10}},
        {"Коваленко", 104, {2, 3, 3, 2, 3}},
        {"Шевченко", 105, {11, 12, 11, 12, 11}}
    };

    print1(students, n);
    cout << "\n";
    print2(students, n);
    
    students=IncreaseNumber(students, n, 10);
    n=10;

    delete[] students;
    
    return 0;
}
