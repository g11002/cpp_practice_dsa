#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

// second largest element in array
int getSecondLargest(vector<int> &arr) {
    int maxi = INT_MIN;
    int ans = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        maxi = max(maxi, arr[i]);
    }
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != maxi) {
            ans = max(ans, arr[i]);
        }
    }

    return (ans == INT_MIN) ? -1 : ans;
}
// heap approach
int getSecondLargest(vector<int> &arr) {
    priority_queue<int>pq;
    for(int i=0;i<arr.size();i++) {
        pq.push(arr[i]);
    }
    int top = pq.top();
    pq.pop();
    while(!pq.empty()) {
        if(top==pq.top()) {
            top = pq.top();
            pq.pop();
        } else {
            return pq.top();
        }
    }
    return -1;
}
// majority element in array
int majorityElement(vector<int>& arr) {
    unordered_map<int,int>freq;
    int n=arr.size();
    for(int i=0;i<n;i++) {
        freq[arr[i]]++;
    }
    for(int i=0;i<n;i++) {
        if (freq[arr[i]]>n/2) {return arr[i];};
    }
    return -1;
}

//  paranthesis checker
// Input: s = "[{()}]"
// Output: true
// Input: s = "[()()]{}"
// Output: true

bool matching(char a, char b) {
    return (a=='{'&&b=='}'|| a=='('&& b==')'||a=='['&&b==']');
}
bool ispar(string s)
{
    // Your code here
    stack<char>st;
    for(int i = 0; i<s.length(); i++) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
            st.push(s[i]);
        } else {
            if(st.empty()==true) return false;
            if(matching(st.top(),s[i])==false) return false;
            else st.pop();
        }
    }
    return (st.empty()==true);
}

// give k largest element in array in decreasing order
vector<int> kLargest(vector<int>& arr, int k) {
    // Your code here
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++) {
        pq.push(arr[i]);
    }
    for(int i=k;i<arr.size();i++) {
        if(pq.top()<arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<int>ans;
    for(int i=0;i<k;i++) {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    cout << "test" << endl;
    return 0;
}