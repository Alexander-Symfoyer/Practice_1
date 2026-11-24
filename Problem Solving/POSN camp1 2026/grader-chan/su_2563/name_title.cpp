#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string name, surname, title;
    int gender, ages, married;

    cin >> name >> surname >> gender >> ages >> married;
    
    if (gender == 1) {
        if (ages < 15) {
            title = "Master";
        }
        else {
            title = "Mr.";
        }
    }
    else {
        if (ages < 15) {
            title = "Miss";
        }
        else {
            if (married == 0) {
                title = "Miss";
            }
            else {
                title = "Mrs.";
            }
        }
    }

    cout << title << " " << name << " " << surname << '\n';

}