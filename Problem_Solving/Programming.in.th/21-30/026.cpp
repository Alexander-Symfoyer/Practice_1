#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Team {
    string name;
    int points = 0;
    int goaldiffs = 0;
    int goals = 0;
};

void calculate(vector<vector<int>> &v, vector<Team> &teams) {

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            if (i == j) continue;

            if (v[i][j] > v[j][i]) {
                teams[i].points += 3;
            } 

            else if (v[i][j] == v[j][i]) {
                teams[i].points += 1;
            }
            
            teams[i].goaldiffs += v[i][j] - v[j][i];
            teams[i].goals += v[i][j];

        }
    }
}
    
void sort_team(vector<Team> &teams) {

    sort(teams.begin(), teams.end(), [](const Team& a, const Team& b) {     //* Lambda functions
                                                                            //* [] Capture list
                                                                            //* ( ) Parameter
                                                                            //* { } Function body

        if (a.points != b.points) {
            return a.points > b.points;
        }

        if (a.goaldiffs != b.goaldiffs) {
            return a.goaldiffs > b.goaldiffs;
        }

        return a.goals > b.goals;

    });

}


void print(vector<Team> &teams) {

    for (const Team& team : teams) {

        cout << team.name << " " << team.points << '\n';

    }

}




int main() {

    vector<vector<int>> v(4, vector<int>(4));

    vector<Team> teams;
    for (int i = 0; i < 4; i++) {
        string n;
        cin >> n;
        teams.push_back({n, 0, 0, 0});
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> v[i][j];
        }
    }


    calculate(v, teams);
    sort_team(teams);
    print(teams);

}