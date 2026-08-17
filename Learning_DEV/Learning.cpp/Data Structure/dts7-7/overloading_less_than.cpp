#include <iostream>
#include <queue>
#include <string>

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

                //? this -> a , other -> b
                    //! Protect the argument (don't change other)
                                        //! Protect this object (don't change this )
        
        return gpax < other.gpax;       
    }
    string getName() const {
        return name;
    }

private:
    float gpax;
    string name, surname;
};

int main() {
    Student a(2.95, "nattee", "niparpan");
    Student b(4.00, "attawich", "sudsang");

    cout << (a < b) << endl;        //* a.operator < (b)
    priority_queue<Student> pq;
    pq.push(a);
    pq.push(b);

    cout << pq.top().getName() << endl;

}