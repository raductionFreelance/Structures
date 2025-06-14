#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

struct Man {
    int position;
    string surname;
    string name;
    int age;
    tm dateOfBirth;
};

bool compareBySurname(const Man &a, const Man &b)
{
    return a.surname.size() < b.surname.size();
}

void sortBySurname(vector<Man>& men) {
    sort(men.begin(), men.end(), compareBySurname);
    for (const Man& man:men){
        cout << man.surname << " " << man.name << " " << man.age << " " << man.dateOfBirth.tm_year+1900 << " "<< man.dateOfBirth.tm_mon+1 << " " << man.dateOfBirth.tm_mday << endl;
    }
}

void printDate(vector<Man>& men, int n){
    for (const Man& man:men){
        if (man.dateOfBirth.tm_mon+1==n){
            cout << man.surname << " " << man.name << " " << man.age << " " << man.dateOfBirth.tm_year+1900 << " "<< man.dateOfBirth.tm_mon+1 << " " << man.dateOfBirth.tm_mday << endl;
        }
    }
}

void SearchByName(vector<Man>& men, string name){
    for (const Man& man:men){
        if (man.name==name){
            cout << man.surname << " " << man.name << " " << man.age << " " << man.dateOfBirth.tm_year+1900 << " "<< man.dateOfBirth.tm_mon+1 << " " << man.dateOfBirth.tm_mday << endl;
        }
    }
}

void SearchBySurname(vector<Man>& men, string surname){
    for (const Man& man:men){
        if (man.surname==surname){
            cout << man.surname << " " << man.name << " " << man.age << " " << man.dateOfBirth.tm_year+1900 << " "<< man.dateOfBirth.tm_mon+1 << " " << man.dateOfBirth.tm_mday << endl;
        }
    }
}

void edit(vector<Man>& men, int n){
    cout << "Введіть нове імʼя";
    cin >> men[n].name;
    cout << "Введіть нове прізвище";
    cin >> men[n].surname;
    cout << "Введіть новий вік";
    cin >> men[n].age;
    cout << "Введіть нову дату народження";
    cin >> men[n].dateOfBirth.tm_year;
    men[n].dateOfBirth.tm_year-=1900;
    cin >> men[n].dateOfBirth.tm_mon;
    men[n].dateOfBirth.tm_mon-=1;
    cin >> men[n].dateOfBirth.tm_mday;
}

int main() {
    vector<Man> men = {
        {1, "Ivanov", "Ivan", 30, {0,0,0,15,4,90}},
        {2, "Petrov", "Petr", 25, {0,0,0,20,6,95}},
        {3, "Sidorov", "Sidr", 40, {0,0,0,5,0,80}}
    };

    cout << "\nСортування";
    sortBySurname(men);

    cout << "\nПошук за імʼям";
    SearchByName(men, "Petr");
    
    cout << "\nПошук за прізвищем";
    SearchBySurname(men, "Ivanov");

    cout << "\nВивід дати народження";
    printDate(men, 5);

    cout << "\nРедагування";
    edit(men, 0);

    cout << "\nСортування";
    sortBySurname(men);

    return 0;
}
