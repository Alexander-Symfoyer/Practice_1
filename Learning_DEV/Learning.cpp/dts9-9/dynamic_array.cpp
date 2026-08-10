#include <iostream>

using namespace std;

class test{
public:

    //* constructor
    //* automatically call when an object is created
    //* initialize member variable
    test() : data() {cout << "created" << '\n';}        //? Initailizer list (create data with default value (0))


    //* destructor
    //* automatically call before an object is destroyed
    //* use to clean up resource 
    ~test() {cout << data <<  " destroyed " << '\n';}

    int data;

};

int main() {

    //! - single object -

    test *a, *b;

    a = new test;           // allocate one object on the heap and call constructor
    a->data = 10;           // access member through pointer
    cout << a->data << '\n';
    delete a;               // destroy the object and call destructor
                            // memory is returned to the heap



    //! - Dynamic array -

    b = new test[4];        // allocate 4 call 4
    b[0].data = 10; 
    b[1].data = 20;
    b[2].data = 30;
    b[3].data = 40;
    delete [] b;            // destroy the entire array 
                            // destructor is called for every element

    return 0;       //! for everything that is created by new, we must call delete
                    //! if you do not, that memory is not deleted until all memory is used up

}