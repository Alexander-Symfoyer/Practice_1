#include <iostream>
#include <queue>
#include <string>

using namespace std;

string operator*(string & lhs, const int & rhs) {       //* lhs = left hand side , rhs = right hand side
    
    string result = "";                                 //! const = constant (Don't modify)
    for (int i = 0; i < rhs; i++) {                     //* & Reference
        result = result + lhs + " ";
    }
    return result;

}


int main() {
    string a = "abc";
    cout << (a * 3) << endl;
}