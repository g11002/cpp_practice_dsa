#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

// group anagrams
// Input: strs = ["act","pots","tops","cat","stop","hat"]
// Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> res;
    for (auto s: strs) {
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());
        res[sorted_s].push_back(s);
    }
    vector<vector<string>> result;
    for (auto i: res) {
        result.push_back(i.second);
    }
    return result;
}

int main() {
    vector<vector<string>> res;
    return 0;
}