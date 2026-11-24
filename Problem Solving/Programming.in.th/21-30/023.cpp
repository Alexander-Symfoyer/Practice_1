#include <iostream>
#include <map>
using namespace std;
int main() {

    int d,m;
    cin >> d >> m;
    map<int, string> m1 = {
        {1, "Thursday"}, {2, "Friday"}, {3, "Saturday"}, {4, "Sunday"},
        {5, "Monday"}, {6, "Tuesday"}, {0, "Wednesday"}
    };
    map<int, int> m2 = {
        {1, 0}, {2, 31}, {3, 59}, {4, 90}, {5, 120}, {6, 151}, 
        {7, 181}, {8, 212}, {9, 243}, {10, 273}, {11, 304}, {12,334}
    };

    int output = (d + m2[m]) % 7;
    cout << m1[output];

}