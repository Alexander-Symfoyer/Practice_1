#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int days, first, birth;
    cin >> days >> first >> birth;
    int lucky = 0;
    int temp = 1;
    int count = 0;
    vector<vector<int>> calender;
    calender.push_back({});

    while (temp != first) {

        temp++;
        calender[0].push_back(0);
        count++;

    }
    
    int j = 0;
    int column;

    for (int i = 1; i <= days; i++) {

        if (count < 7) {
            calender[j].push_back(i);
            count++;
        }
        else {
            j++;
            count = 1;
            calender.push_back({});
            calender[j].push_back(i);
        }
        if (i == birth) {
            column = count - 1;
        }

    }

    if (birth - 7 > 0) {
        lucky += birth - 7;
    }
    if (birth + 7 <= days) {
        lucky += birth + 7;
    }


    if (column < 6 && birth != days) {
        lucky += birth + 1;
    }
    if (column > 0 && birth != 1) {
        lucky += birth - 1;
    }

    cout << lucky;

}