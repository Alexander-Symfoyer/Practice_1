#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    void setFullname(string name, string surname) {
        this->name = name;
        this->surname = surname;            // pointer

    }
    string getFullname() {
        return "[" + name + " " + surname + "]";
    } 
private:
    string name,surname;
};

int main() {
    Student a;      //* object(a,b)
    Student b;      // empty
    a.setFullname("nattee", "niparnan");
    cout << a.getFullname() << endl;
    cout << b.getFullname() << endl;
}