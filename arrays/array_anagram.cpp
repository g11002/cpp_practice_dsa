#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

bool is_anagram1(string &s, string &t) {
    if (s.length() != t.length()) {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

bool is_anagram2(string &s, string &t) {
    if (s.length() != t.length()) {
        return false;
    }
    unordered_map<char,int> count_s;
    unordered_map<char,int> count_t;
    for(int i=0;i<s.length();i++) {
        count_s[s[i]]++;
        count_t[t[i]]++;
    }
    return count_s == count_t;
}

int main() {
    string s = "racecar", t = "carrace";
    // s = "jar", t = "jam"
    bool val = false;
    val = is_anagram1(s,t);
    cout << val << endl;
    cout << is_anagram2(s,t) << endl;
    return 0;
}