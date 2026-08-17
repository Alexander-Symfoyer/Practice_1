#include <iostream>         //* mdv = maximum diffent value in an array
#include <vector>
#include <algorithm>

using namespace std;

int two_diff(vector<int> &v) {

    int mx = *max_element(v.begin(), v.end());      //! * = dereference
    int mn = *min_element(v.begin(), v.end());

    return mx - mn;

}

int main() {

    vector<int> v;
    v = {1,2,4,314,6,254,656,234};
    cout << two_diff(v) << '\n';

}
