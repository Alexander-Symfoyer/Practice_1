#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> years;
    int max_year = INT_MIN;
    while (true) {
        int year;
        cin >> year;
        max_year = max(max_year, year);
        if (year == -1) break;
        if (year < 1 || year > 24) return 0;
        years.push_back(year);
    }
    
    vector<int> worker_at(max_year + 1);
    vector<int> total_at(max_year + 1);
    
    int queen = 1;
    int worker = 1;
    int soldier = 0;
    for (int i = 1; i <= max_year; i++) {
        int old_worker = worker;
        int old_soldier = soldier;
        worker += (soldier + worker + queen);
        soldier += (old_worker);
        worker -= old_worker;
        soldier -= old_soldier;
        
        worker_at[i] = worker;
        total_at[i] = worker + queen + soldier;
        
    }
    
    for (const int& year : years) {
        cout << worker_at[year] << " " << total_at[year] << '\n';
    }
    
}