#include <iostream>
#include <algorithm>

using namespace std;

int find(int &a, int &b) {

    for (int i = 1; i < max(a,b); i++) {
        if((a % i == 0) && (b % i == 0)) {
            cout << i << " ";
        }
    }
    cout << '\n';

}


int main() {
    
    int a,b;
    cout << "Enter a : ";
    cin >> a; 
    cout << "Enter b : ";
    cin >> b;
    find(a,b);

}