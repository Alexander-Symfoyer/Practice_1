#include <bits/stdc++.h>
using namespace std;
int main() {

    int arr[10] = {0};

    for (int i = 0; i < size(arr); i++) {
        arr[i] = i + 1;
    }

    int sum = 0;

    for (int i = 1; i <= size(arr); i++) {
        sum += i;
    }

    int maximum = 0;
    for (int i = 0; i < size(arr); i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }

    for (int i : arr) {
        cout << i << " ";
    }   cout << '\n';

    cout << sum << " " << maximum;

}