#include <iostream>
#include <vector>
#include <set>


using namespace std;

bool subset_sum(
    const vector<int> &a,
    int index,
    int target,
    vector<int> &ans
)   {

    if (target == 0) return true;               //* Target reached --> solution founded

    if (target < 0) return false;               //! Target exceeded

    if (index == a.size()) return false;        //* No element left --> no solution

    ans.push_back(index);                       //* Try including this element

    if (subset_sum(a, index + 1, target - a[index], ans)) {         
        return true;
    }   
    
    ans.pop_back();                                 //* Including it failed --> try Backtracking
    if (subset_sum(a, index + 1, target, ans)) {    //* Try excluding this element
        return true;
    }

    return false;                   //* Neither choices work

}


int main() {

    vector<int> a = {2,3,5,7};
    int k = 10;

    vector<int> ans;

    if (subset_sum(a, 0, k, ans)) {
        cout << "Found: ";

        for(int i : ans) {
            cout << a[i] << " ";
        }
        cout << '\n';

    } else {
        cout << "No solution\n";
    }

}


