#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cout << "Please enter two words: ";
    cin >> s1 >> s2;
    cout << s1 << endl;
    cout << s2 << endl;

    cout << "The length is " << s1.length() << endl;
    cout << "First char: " << s1[0] << endl;
    cout << "Last char: " << s1[s1.length()-1] << endl;

    string s = "Somchai";
    s[2] = 'n';
    s[3]++;
    s[4] = 67;
    cout << s << endl;
    int x = s[0];
    cout << x << endl;

    s = "Somchai";
    cout << s.substr(0,4)  << endl;
    cout << s.substr(4,999) << endl;
    cout << s.substr(3,2) << endl;
    cout << s.substr(6,0)  << endl;
    cout << s.substr(1) << endl;

    string f = "789";
    int a;
    a = f[0] - '0';
    cout << a << endl;
    a = f[1] - '2';     // ('8' = 56) - ('2' = 50) = 6  <--ascii
    cout << a << endl;
    a = stoi(f);
    cout << a + 1000 << endl;

    string p;   int q;
    p = "1FF";
    q = stoi(p,0,16);
    cout << q << endl;

    p = "100101";
    q = stoi(p,0,2);
    cout << q << endl;

    string s3 = "Somchai", s4 = "aa";
    cout << s3 + s4 << endl;

    cout << s3.find("chai") << endl;
    cout << s3.find("om", 1) << endl;
    cout << s3.find("car") << endl;

}

// substr (a,b)
// a = position
// b = amount

// stoi(a, b, c)
// a = string, b = position, c = base 