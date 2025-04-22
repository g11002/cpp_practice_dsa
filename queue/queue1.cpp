#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    stack<int>s;
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    cout << "Queue elements in reverse: " << endl;
    while(!s.empty()) {
        cout << s.top() << " ";
        q.push(s.top());
        s.pop();
    }
    return 0;
}