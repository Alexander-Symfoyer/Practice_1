#include <iostream>
using namespace std;

int main() {
    
    int r,c;
    cout << "Enter row and column : ";
    cin >> r >> c;
    int i = 0;
    
    while (i < r) {
        int j = 0;
        while (j < c) {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
    

}