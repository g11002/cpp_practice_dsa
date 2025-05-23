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
// Example 1: find common characters
// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]
// Example 2:
// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]
bool check_in_strings(string s, vector<string> words) {
    for (auto it : words) {
        if (it.find(s) == string::npos) {
            return false;
        }
    }
    return true;
}

int count_freq_word(char s, vector<string> words) {
    int countt=0;
    int new_count=INT_MAX;
    string first_word = words[0];
    countt = count(first_word.begin(), first_word.end(), s);
    for(int i=1;i<words.size();i++) {
        new_count = count(words[i].begin(), words[i].end(),s);
        countt = min(countt, new_count);
    }
    return countt;
}

vector<string> commonChars(vector<string>& words) {
    unordered_map<char,int>freq;
    int n=words.size();
    vector<string>ans;
    for(auto it: words) {
        for(auto i:it) {
            freq[i]++;
        }
    }
    for(auto it: freq) {
        if (it.second >= 1) {
                string val_str(1, it.first); 
            bool state = check_in_strings(val_str, words);
            if (state) {
                int min_freq_per_word = count_freq_word(it.first, words);
                while(min_freq_per_word--) {
                    ans.push_back(val_str);
                }
            } else {
                continue;
            }
        }
    }
    return ans;
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
