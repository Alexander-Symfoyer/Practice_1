#include <iostream>
#include <array>

using namespace std;

int main() {
    pair< array<int,5>, pair<int,bool> > p;

    p.first[0] = 10;
    p.first[1] = 20;
    p.second.first = 70;
    p.second.second = false;

    cout << p.first[1] << " " << p.second.second << endl;
}