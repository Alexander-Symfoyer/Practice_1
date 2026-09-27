#include <iostream>
using namespace std;
int main() {

    int jump, distance;
    cin >> jump >> distance;
    if (jump > distance) {
        cout << 2;
    } 
    else {
        cout << (distance + jump - 1) / jump;
    }

}