#include <iostream>
#include <string>

using namespace std;


class Student {
public:
    Student(float score) {      //* Constructor
        gpax = score;
    }
    void setFullname(string name, string surname) {
        this->name = name;
        this->surname = surname;
    }
    string getFullname() {
        return "[" + name + " " + surname + "]";
    }
    bool is1sthorner() {
        return gpax >= 3.6;
    }

private:
    string name, surname;
    float gpax;
};  


int main() {
    Student a(2.95);
    a.setFullname("nattee", "niparpan");
    cout << a.getFullname() << endl;
    if (a.is1sthorner()) {
        cout << "Yes" << endl;
    } else {
        cout << "NO" << endl;
    }
}