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
    int getGpax() const {
        return gpax;
    }

private:
    float gpax;
    string name, surname;
};

class StudentByNameComparator {     //* funcition object
public:
    bool operator()(const Student& lhs, const Student& rhs) {
        return lhs.getName() < rhs.getName();
    }
};

class GpaxThenName {                //* funcition object
public:
    bool operator()(const Student& lhs, const Student& rhs) {
        
        //? Funcition call oparator ( () )
        
        if (lhs.getGpax() == rhs.getGpax()) {
            return lhs.getName() < rhs.getName();
        }
        return lhs.getGpax() < rhs.getGpax();
    }
};

int main() {

    Student a(2.67, "techit", "sangsawang");
    Student b(4.00, "nichanat", "prathumma");
    Student c(4.00, "gantiya", "thewachay");
    cout << (a < b) << endl;

    StudentByNameComparator comp1;  // create object
    GpaxThenName comp2;                             //* Template parameter
    priority_queue< Student, 
                                //* Element types
                                //* Type of objects stored in the queue

                    vector<Student> , 
                                //* Internal storages
                                //* stores elements inside a vector

                    StudentByNameComparator> pq(comp1);
                                //* Comparison rule
    //? priority_queue< what to store? , where to store? , how to compare? >


    pq.push(a);
    pq.push(b);
    cout << pq.top().getName() << endl;

    priority_queue< Student,            //]
                    vector<Student> ,   //| Type
                    GpaxThenName>       //]
                    pq2(comp2);         //  Object     //! comp2.operator()(lhs, rhs)

    pq2.push(a);
    pq2.push(b);
    pq2.push(c);
    cout << pq2.top().getName() << endl;    

}
