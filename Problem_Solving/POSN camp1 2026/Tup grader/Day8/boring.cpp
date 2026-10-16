#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string input, shelf;
    cin >> input;
    vector <char> target, output;
    for(int i = 0; i < m; i++){
        target.push_back(input[i]);
    }
    for(int i = 0; i < 3; i++){
        cin >> shelf;
        for(int j = 0; j < shelf.size(); j++){
            if (count(target.begin(), target.end(), shelf[j]) >= 1) continue;
            output.push_back(shelf[j]);
        }
        if(output.empty()){ 
            cout << "-";
        }
        else{
            for (const char& c : output){ 
                cout << c;
            }
        }
        output.clear();
        cout << "\n";
    }
    return 0;
}