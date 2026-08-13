#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


void print_2d(vector<vector<int>> &v) {

    for (int i = 0; i < v.size(); i++) {

        for (int j = 0; j < 1; j++){

            cout << "{" << v[i][j] << "," << v[i][j+1] << "}" << " ";
            
        }
    }
    cout << '\n';

}


void find(vector<vector<int>> &v) {

    int minx = v[0][0]; int maxx = v[0][0];
    int miny = v[0][1]; int maxy = v[0][1];

    for (auto &p : v) {

        minx = min(minx, p[0]);
        maxx = max(maxx, p[0]);
        miny = min(miny, p[1]);
        maxy = max(maxy, p[1]);

    }

    cout << "(" << minx << "," << miny << ")" << " ";
    cout << "(" << maxx << "," << maxy << ")" << " ";
    cout << '\n';

}


void input_2d(vector<int> &v, vector<vector<int>> &v_2d ) {

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

}



int main() {

    vector<int> v;
    vector<vector<int>> v_2d;
    
    input_2d(v, v_2d);

    find(v_2d);

}