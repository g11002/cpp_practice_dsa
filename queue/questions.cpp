#include <iostream>
#include <algorithm>
#include <string.h>
#include <bits/stdc++.h>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

// Input : S = "abcddabac"
// Output : 4
// Explanation : The answer is "abcd" , with a length of 4.
// Input : S = "aaabbbccc"
// Output : 2
// Explanation : The answers are "ab" , "bc". Both have maximum length 2.
int longestNonRepeatingSubstring(string& s){
        //your code goes here
    unordered_set<char>set;
    queue<char>q;
    int length = INT_MIN;
    for(auto it:s) {
        if (set.find(it)==set.end()) {
            q.push(it);
            set.insert(it);
        } else {
            if (q.size() && q.back()==it) {
                while(!q.empty()) {
                    q.pop();
                }
                set.clear();
                q.push(it);
                set.insert(it);
            } else {
                while(true) {
                    if(q.front()==it) {
                        set.erase(q.front());
                        q.pop();
                        q.push(it);
                        set.insert(it);
                        break;
                    }
                    set.erase(q.front());
                    q.pop();
                }

            }
        }
        int size = q.size();
        length=max(length, size);
    }
    return length;
}

// vector<int> nextLargerElement(vector<int> arr) {
//     vector<int> res;
//     stack<int> s;
//     res.push_back(-1);
//     int n=arr.size()-1;
//     if(n>1) {s.push(arr.back());}
//     while(n--) {
//         if(s.top()>arr[n]) {
//             res.insert(res.begin(), s.top());
//             s.push(arr[n]);
//         } else {
//             if (s.top()<arr[n] && !s.empty()) {
//                 while(!s.empty()) {
//                     if(s.top()>arr[n]) {
//                         res.insert(res.begin(), s.top());
//                         s.push(arr[n]);
//                         break;
//                     }
//                     s.pop();
//                 }
//                 if(s.empty()) {
//                     res.insert(res.begin(), -1);
//                     s.push(arr[n]);
//                 }
//             }
//         }
//     }
//     return res;
// }

// direct array
vector<int> nextLargerElement(vector<int> &arr) {
    int n=arr.size();
    vector<int> res(n,-1);
    stack<int> s;
    for(int i=n-1;i>=0;--i) {
        while(!s.empty() && arr[i]>=s.top()) {
            s.pop();
        }
        if(!s.empty()) {
            res[i]=s.top();
        }
        s.push(arr[i]);
    }
    return res;
}

//for circular integer array
vector<int> nextGreaterElements(vector<int> &arr) {
    int n=arr.size();
    vector<int> res(n,-1);
    stack<int> s;
    int maxval=INT_MIN;
    for(int i=2*n-1;i>=0;--i) {
        int ind = i%n;
        while(!s.empty() && arr[ind]>=s.top()) {
            s.pop();
        }
        if(!s.empty()) {
            res[ind]=s.top();
        }
        s.push(arr[ind]);
    }
    return res;
}

vector<vector<int>>generateSubArray(vector<int>&arr) {
    int n=arr.size();
    vector<vector<int>>res;
    for(int i=0;i<n;i++) {
        vector<int>temp;
        for(int j=i;j<n;j++) {
            temp.push_back(arr[j]);
            res.push_back(temp);
        }
    }
    return res;
}

vector<int>getMinInSubArray(vector<vector<int>>&arr) {
    vector<int>res;
    for(auto it:arr) {
        auto minVal = INT_MAX;
        for(auto i:it) {
            minVal=min(minVal,i);
        }
        res.push_back(minVal);
    }
    return res;
}

int sumSubarrayMins(vector<int> &arr) {
    int sum=0;
    vector<vector<int>>allSubArray = generateSubArray(arr);
    vector<int>minSubArray = getMinInSubArray(allSubArray);
    for(auto it:minSubArray) {
        sum+=it;
    }
    return sum;
}
// analysed the brute force approach and seeing the optimal solution analysed
// --> first case
// [1,2,3] if array is jumbled sort it once
// 1*3+2*2+3*1=10 is ans
// --> second case
// [11,81,94,43,3]
// [3,11,43,81,94] after sorting
// 3*5+11*4+43*3+81*2+94==444is ans
int sumSubarrayMins_alternate1(vector<int> &arr) {
    //not working, not correct //
    int n=arr.size();
    int temp=n;
    sort(arr.begin(), arr.end());
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=arr[i]*temp;
        temp--;
    }
    return sum;
}

int sumSubarrayMins_alternate2(vector<int> &arr) {
    int n=arr.size();
    int sum=0;
    int minval=INT_MAX;
    for(int i=0;i<n;i++) {
        minval=INT_MAX;
        for(int j=i;j<n;j++) {
            minval=min(minval,arr[j]);
            sum+=minval;
        }
    }
    return sum;
}

// rain water trapping problem - O(n) - first solution
vector<int> findLeftMax(vector<int> &arr, int &n) {
    vector<int> left(n);
    left[0] = arr[0];
    for(int i=1; i < n; i++) {
        left[i] = max(left[i-1], arr[i]);
    }
    return left;
}
vector<int> findRightMax(vector<int> &arr, int &n) {
    vector<int> right(n);
    right[n-1] = arr[n-1];
    for(int i=n-2; i >= 0; i--) {
        right[i] = max(right[i+1], arr[i]);
    }
    return right;
}
int trap(vector<int> &height){
    int n = height.size();
    int total = 0;
    vector<int> leftMax = findLeftMax(height, n);
    vector<int> rightMax = findRightMax(height, n);
    for(int i=0; i < n; i++) {
        if(height[i] < leftMax[i] && height[i] < rightMax[i]) {
            total += min(leftMax[i], rightMax[i]) - height[i];
        }
    }
    return total;
}
// rain water trapping problem - O(n) - second solution
int trap(vector<int> &height){
    int n=height.size();
    int total=0;
    int leftMax=0, rightMax=0;
    int left=0, right=n-1;
    while(left<right) {
        if(height[left]<=height[right]) {
            if(leftMax>height[left]) {
                total+=leftMax-height[left];
            } else {
                leftMax = height[left];
            }
            left=left+1;
        } else {
            if(rightMax>height[right]) {
                total+=rightMax-height[right];
            } else {
                rightMax = height[right];
            }
            right=right-1;
        }
    }
    return total;
}
// max rectangular area within the heights
// brute force approach
int largestRectangleArea(vector<int> &heights) {
    int n=heights.size();
    int area = INT_MIN;
    for(int i=0;i<n;i++) {
        int minval = INT_MAX;
        int curr = INT_MIN;
        int count = 0;
        for(int j=i;j<n;j++) {
            if (heights[j]==0) {
                break;
            } else if(heights[j]<minval) {
                minval = heights[j];
                count++;
            } else {
                count++;
            }
            curr = minval*count;
            area = max(area, curr);
        }
    }
    if (area == INT_MIN) return 0;
    return area;
}

int main() {
    // vector<int> arr = {6, 8, 0, 1, 3};
    // vector<int> arr = {1,3,2};
    vector<int> arr = {1,2,3,4};
    // arr = nextLargerElement(arr);
    // for(auto it:arr) {cout<<it<<" ";}
    vector<vector<int>> res = generateSubArray(arr);
    for(auto it:res) {
        for(auto i:it) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    vector<int>min_array = getMinInSubArray(res);
    int sum=0;
    for(auto it:min_array) {
        sum+=it;
    }
    cout<<"Sum of Subarray Minimums: "<< sum << endl;
    vector<int>arr1 = {3,1,2,5};
    int val = sumSubarrayMins_alternate2(arr1);
    cout<< "sum array min sum: " << val << endl;

    return 0;
}