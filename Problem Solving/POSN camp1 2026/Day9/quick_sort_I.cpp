#include <bits/stdc++.h>
using namespace std;

int partition (vector<int>& arr, int left, int right) {

    int pivot = arr[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return (i + 1);

}

void quick_sort(vector<int>& arr, int left, int right) {

    if (left < right) {
        int pi = partition(arr, left, right);
        quick_sort(arr, left, pi - 1);
        quick_sort(arr, pi + 1, right);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quick_sort(arr, 0, arr.size() - 1);

    cout << "Information after sorting is : ";
    for (const int& i : arr) {
        cout << i << " ";
    }   cout << '\n';

    cout << "The minimum value is ";
    cout << arr[0] << '\n';
    cout << "The maximum value is ";
    cout << arr[arr.size() - 1] << '\n';

    return 0;
}