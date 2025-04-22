#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2(5,10);
    vector<int> v3 = {1,2,3,4,5};
    for(auto it = v3.begin(); it != v3.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for(auto it :v3) {
        cout<< it<< " ";
    }
    cout<< endl;
    for(size_t i=0; i<v3.size(); i++) {
        cout<< v3[i]<< " ";
    }
    cout<<endl;
    vector<int> v = v3;
    v.push_back(6);
    for(auto it: v) {
        cout<< it;
    }
    cout<<endl;
    cout<<v.front();
    cout<<endl;
    cout<<v.back()<<endl;
    v.pop_back();
    for(auto it: v) {
        cout<<it;
    }
    cout<<endl;
    sort(v.begin(), v.end());
    for(auto it: v) {
        cout<<it;
    }
    cout<<endl;
    reverse(v.begin(), v.end());
    for(auto it: v) {
        cout<<it;
    }
    cout<<endl;
    cout<<v[1]<<endl;
    cout<<v.at(1)<<endl;


    // vector<int> vec(100, 0);
    vector<int> vec;
    cout << vec.capacity() << endl; // 100
    cout << vec.size() << endl;
    vec.push_back(1);
    cout << vec.capacity() <<endl;
    cout << vec.size() << endl;
    return 0;
}