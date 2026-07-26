#include <iostream>
#include <set>
#include <map>
#include <string>


using namespace std;


class Student {

public:
    
    Student(string name, string surname, float gpax) {
        this->name = name;
        this->surname = surname;
        this->gpax = gpax;
    }

    string getname() const {
        return name;
    }

    string getsurname() const {
        return surname;
    }

    float getgpax() const {
        return gpax;
    }

private:
    string name, surname;
    float gpax;

};  


class StudentComparator {

public:
    bool operator()(const Student& lhs, const Student& rhs) const {

        if (lhs.getgpax() > rhs.getgpax()){
            return true;
        } 
        else {
            
            if (lhs.getgpax() == rhs.getgpax()) {
                
                if (lhs.getname() != rhs.getname()) {
                    return lhs.getname() > rhs.getname();

                }
                
                else {
                    return lhs.getsurname() > rhs.getsurname();

                }
            }
            
            return false;
        }

    }    

};


int main() {

    Student a("nakano", "miku", 3.20);
    Student b("nakano", "nino", 3.50);
    Student c("nakano", "itsuki", 3.50);
    Student d("uesugi", "futaro", 4.00);

    set<Student , StudentComparator> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);

    for (const Student& x : s){
        cout    << x.getname() << " "
                << x.getsurname() << " "
                << x.getgpax() << endl;
    }

    map<Student, int, StudentComparator> m;
    m[a] = 59000;
    m[b] = 58097;
    m[c] = 59011;
    m[d] = 58084;

    for (const auto& x : m){
        cout << x.second << endl;
    }

}
