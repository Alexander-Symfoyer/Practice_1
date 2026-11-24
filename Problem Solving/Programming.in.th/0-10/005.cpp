#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    double a,b;
    cin >> a >> b;
    double output = sqrt((a*a) + (b*b));
    cout << fixed << setprecision(6) << output;
    return 0;

}