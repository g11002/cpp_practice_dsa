#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> check_2sum(vector<int> &nums, int &target) {
    for (int i=0;i<nums.size();i++) {
        for (int j=i+1;j<nums.size();j++) {
            if (nums[i]+nums[j] == target) {
                return {i,j};
            }
        }
    }
    return {};
}

vector<int> check_2sum_1(vector<int> &nums, int &target) {
    unordered_map<int,int>indices;
    for(int i=0;i<nums.size();i++) {
        indices[nums[i]] = i;
    }
    for(int i=0;i<nums.size();i++) {
        int diff = target - nums[i];
        if (indices.count(diff) && indices[diff] != i) {
            return {i, indices[diff]};
        }
    }
}

int main() {
    // nums = [3,4,5,6], target = 7
    // Output: [0,1]

    vector<int> nums = {3,4,5,6};
    int target = 7;
    vector<int>res;
    vector<int>res1;
    res = check_2sum(nums, target);
    for (auto i: res) {
        cout << i << " ";
    }
    cout << endl;
    res1 = check_2sum_1(nums, target);
    for (auto i: res1) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}