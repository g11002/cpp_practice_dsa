#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "s.top(): " << s.top() << endl;
    cout << "s.size(): "<< s.size() << endl;
    if (!s.empty()) {
        cout << "s.size(): "<< s.size() << endl;
    }
    while(!s.empty()) {
        cout << s.top() << " " << endl;
        s.pop();
    }
    cout << "s.size(): "<< s.size() << endl;
    return 0;
}