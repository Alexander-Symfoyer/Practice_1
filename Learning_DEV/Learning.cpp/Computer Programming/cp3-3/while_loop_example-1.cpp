#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int i = 1, n;
    cout << "Enter n : "; cin >> n;
    while (i <= n) {
        sum += i;
        i++;
    }
    cout << "Summation is : " << sum << endl;

    sum = 0;
    while (n--) sum += n+1;
    cout << "Sum is : " << sum << endl;  // incorrect

}