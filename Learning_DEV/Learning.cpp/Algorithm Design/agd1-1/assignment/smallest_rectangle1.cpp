#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


void superprint(vector<vector<int>> &v) {

    for (int i = 0; i < v.size(); i++) {

        for (int j = 0; j < 1; j++){

            cout << "{" << v[i][j] << "," << v[i][j+1] << "}" << " ";
            
        }
    }
    cout << '\n';

}


void find(vector<vector<int>> &v) {

    vector<int> row;
    vector<int> col;

    for (int i = 0; i < v.size(); i++) {

        row.push_back(v[i][0]);
        col.push_back(v[i][1]);

    }

    int r1 = *min_element(row.begin(), row.end());
    int r2 = *max_element(row.begin(), row.end());
    int c1 = *min_element(col.begin(), col.end());
    int c2 = *max_element(col.begin(), col.end());

    cout << "(" << r1 << "," << c1 << ")" << " ";
    cout << "(" << r2 << "," << c2 << ")" << " ";
    cout << '\n';

}




int main() {

    vector<int> v;
    vector<vector<int>> v_2d;
    
    int n; cout << "Enter number of points : "; cin >> n;

    for (int i = 0; i < n; i++) {

        int a;
        int b;
        
        cout << "Enter points " << i + 1 << " (x) " << " : ";
        cin >> a;
        v.push_back(a);
        
        cout << "Enter points " << i + 1 << " (y) " << " : ";
        cin >> b;
        v.push_back(b);

        v_2d.push_back(v);
        v.clear();
    }
    
    find(v_2d);

}