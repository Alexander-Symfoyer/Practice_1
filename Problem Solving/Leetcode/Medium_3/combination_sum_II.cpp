#include <bits/stdc++.h>
using namespace std;

vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
int target = 8;
vector<vector<int>> soln;

void backtrack(vector<int> current, int target, int start) {

    if (target == 0) {
        soln.push_back(current);
        return;
    }
    else if (target < 0) {
        return;
    }
    else {
        for (int i = start; i < candidates.size(); i++) {

            if (i > start && candidates[i] == candidates[i-1]) {        //* Skip duplicate branch
                continue;
            }

            current.push_back(candidates[i]);
            backtrack(current, target - candidates[i], i + 1);          //* Use each element once (i + 1)
            current.pop_back();

        }
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sort(candidates.begin(), candidates.end());
    backtrack({}, target, 0);

    for (int i = 0; i < soln.size(); i++) {
        for (int j : soln[i]) {
            cout << j << " ";
        }   cout << '\n';
    }

}