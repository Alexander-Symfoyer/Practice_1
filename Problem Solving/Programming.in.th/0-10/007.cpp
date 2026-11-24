#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    double r;
    cin >> r;
    double taxi = 2.0 * r * r;
    double euclidean = M_PI * r * r;

    cout << fixed << setprecision(6);
    cout << euclidean << '\n';
    cout << taxi << '\n';
    return 0;

}