#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int arr[100];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int *p = arr, *q = arr + n - 1; p < q; p++, q--) {
        int temp = *p;
        *p = *q;
        *q = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }   cout << '\n';

}