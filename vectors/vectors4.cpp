#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> give_index(vector<int> &arr, int target) {
        // code here
        vector<int>v;
        vector<int>res;
        int temp;
        while(target) {
            temp = target%10;
            target = target/10;
            v.push_back(temp);
        }
        reverse(v.begin(), v.end());
        // cout<<"intermediate res"<<endl;
        // for(auto it: v) {
        //     cout<<it<< " ";
        // }
        // cout << endl;
        for (auto i = 0; i < v.size(); i++) {
            // cout << v[i] << " ";
            for (auto j = 0; j < arr.size(); j++) {
                // arr[j]
                if (v[i] == arr[j]) {
                    res.push_back(j);
                }
            }
        }
        if (res.size()==0) {
            res.push_back(-1);
        }
        return res;
}
int getSecondLargest(vector<int> &arr) {
    // Code Here
    int maxi=0,ans=-1;
    for(int i:arr){
        if(i>maxi) maxi=i;
    }
    for(int i:arr) {
        if(i<maxi && i>ans ) ans=i;
    }
    return ans;
}

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();
    for(int i=0;i<n;i++){
        freq[nums[i]]++;
    }
    for(int i=0;i<n;i++){
        if(freq[nums[i]]>n/2){
            return nums[i];
        }
    }
    return -1;
}
int main() {
    // vector<int>arr = {1, 2, 3, 7, 5};
    // int target = 12;
    vector<int>arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 15;
    vector<int>res;
    res = give_index(arr, target);
    for(auto it: res) {
        cout<<it<< " ";
    }
    return 0;
}
