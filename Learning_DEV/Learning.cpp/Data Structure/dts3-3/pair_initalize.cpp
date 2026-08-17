#include <iostream>
#include <string>

using namespace std;

int main() {
    //default constructor
    pair<string,bool> p;
    cout << "default [" << p.first << "] [" << p.second << "]" << endl;
    
    //initialize by { }
    pair<string,bool> p1 = { "Somchai", true };

    //create pair without specifying type by "make_pair"
    pair<bool,int> p2;
    cout << p2.first << " " << p2.second << endl;   // bool start with false(0) 
    p2 = make_pair(true,10);                        // int start with 0

    pair<bool,int> p3(p2);
    cout << p3.first << " " << p3.second << endl;

    //more complex pair
    pair< pair<float,int>, string > p4;
    p4 = make_pair(make_pair(20.5, -3), "hello");
    cout << p4.first.first << " " << p4.first.second << " " << p4.second << endl;


    


}