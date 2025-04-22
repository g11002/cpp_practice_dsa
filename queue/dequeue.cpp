#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int>dq;
    dq.push_back(10);
    dq.push_front(5);
    dq.push_back(20);

    cout << "dequeue elements: " << endl;
    for(auto it: dq) cout << it << " ";
    cout << endl;

    cout << "accessing the elements: " << endl;
    cout << "dq.front(): " << dq.front() << endl;
    cout << "dq.back(): " << dq.back() << endl;

    deque<int>d = {10,20,30};
    d.push_front(5);
    d.push_back(40);
    cout << "dequeue elements: " << endl;
    for(auto it: d) cout << it << " ";
    cout << endl;
    d.pop_front();
    d.pop_back();
    cout << "dequeue elements: " << endl;
    for(auto it: d) cout << it << " ";
    cout << endl;

    return 0;
}