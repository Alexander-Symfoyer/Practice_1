#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>


using namespace std;


int main() {

    vector<int> a = {1,2,3};        // compare form left to right
    vector<int> b = {1,2,4};
    cout << (a < b) << endl;

    vector<int> c = {1,2};          // compare form left to right
    vector<int> d = {1,2,3};
    cout << (c < d) << endl;

    vector<int> e = {1};
    vector<int> f = {1};
    cout << (e < f) << endl;

    set<int> g = {1,2,3};
    set<int> h = {1,2,4};
    cout << (g < h) << endl;

    map<int, string> m1 = {{10, "saitama"}, {9, "jenos"}, {8, "garo"}};     
    cout << (m1[9] < m1[10]) << endl;

    map<int ,string> m2 = {{10,"a"}, {30,"d"}};               // compare first then second;
    map<int ,string> m3 = {{10,"a"}, {30,"c"}};
    cout << (m3 < m2) << endl;

    queue<bool> q1;             // compare with deque
    queue<bool> q2;
    q1.push(false);
    q2.push(true);
    cout << (q1 < q2) << endl;

    stack<vector<int>> s1;
    stack<vector<int>> s2;
    s1.push({10,20});
    s2.push({10,40});
    cout << (s1 < s2) << endl;

}

// Container ของ STL จำนวนมากจะมี operator< 
// ถ้าองค์ประกอบที่อยู่ข้างในสามารถเปรียบเทียบกันได้ (<) และ 
// container นั้นรองรับ relational operators