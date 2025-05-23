#include <bits/stdc++.h> 
using namespace std; 

int main(){
    
    unordered_set <int> s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);

    for(int x: s)
        cout<<x<<" ";
    cout<<endl;

    for(auto it=s.begin();it!=s.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    cout << "size:" << endl;
    cout<<s.size()<<endl;
    s.clear();
    cout << "size:" << endl;
    cout<<s.size()<<endl;
    
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    cout << "size:" << endl;
    cout<<s.size()<<endl;
    
    if(s.find(15)==s.end())
        cout<<"Not Found";
    else
        cout<<"Found "<<(*s.find(15));
    cout<<endl;

    if(s.count(15))
        cout<<"Found";
    else
        cout<<"Not Found";
    cout<<endl;
    
    cout<<s.size()<<endl;
    s.erase(15);
    cout<<s.size()<<endl;

    auto it=s.find(10);
    s.erase(it);
    cout << "size:" << endl;
    cout<<s.size()<<endl;
    
    s.erase(s.begin(),s.end());
    cout << "size:" << endl;
    cout << s.size() << endl;

    return 0;
}