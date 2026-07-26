#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Student {
public:
    Student(float score, string a , string b) {
        name = a;
        surname = b;
        gpax = score;
    }
    bool is1stHonor() {
        return gpax >= 3.6;
    }
    bool operator<(const Student& other) const {
        return gpax < other.gpax;       
    }
    string getName() const {
        return name;
    }

private:
    float gpax;
    string name, surname;
};
