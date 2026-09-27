#include <iostream>
#include <string>
using namespace std;
int main() {                            //! string::npos = not found (use find)

    string s = "Hello World";
    cout << s.find("o") << " ";        //* Return index
    cout << s.rfind("d") << " ";       //* find from the back

    cout << s.substr(0,5) << " ";      //* Substring

    s.erase(0,5);
    cout << s << " ";

    s.insert(6,"class");
    cout << s << " ";

    s.replace(0,6, "member");
    cout << s << " ";

    cout << !(s.empty()) << " ";

    cout << s.front() << " " << s.back() << '\n';

    s.push_back('e');       //! 'char'
    s.pop_back();

}