#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    queue<int>t;
    t=q;
    cout << "q.size(): " << q.size() << endl;
    cout << "q.front(): " << q.front() << endl;
    cout << "q.back(): " << q.back() << endl;
    while(!t.empty()) {
        cout << t.front() << " ";
        t.pop();
    }
    cout << endl;
    cout << "t.size(): " << t.size() << endl;
    return 0;
}