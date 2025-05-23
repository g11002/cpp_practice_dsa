#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;

int f(int index, vector<int>heights) {
    // frog jump recursion dp
    if (index == 0) return 0;
    int left = f(index-1, heights) + abs(heights[index] - heights[index-1]);
    int right = INT_MAX;
    if (index>1) right = f(index-2, heights) + abs(heights[index] - heights[index-2]);
    return min(left, right);
}

int jump_rec(int n, vector<int>heights) {
    // frog jump recursion dp
    return f(n-1, heights);
}

int f1(int index, vector<int>heights, vector<int>dp) {
    if (index==0) return 0;
    if (dp[index]!=-1) return dp[index];
    int left = f1(index-1, heights, dp) + abs(heights[index]-heights[index-1]);
    int right = INT_MAX;
    if (index>1) right = f1(index-2, heights, dp) + abs(heights[index]-heights[index-2]);
    return dp[index]= min(left, right);
}

int jump_rec_memo(int n, vector<int>heights) {
    // frog jump recursion dp with memoization -> top down approach
    // tabulation bottom up approach
    vector<int>dp(n+1,-1);
    return f1(n-1, heights, dp);
}

int jump_tabulation_1(int n, vector<int>heights) {
    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++) {
        int first_step = dp[i-1] + abs(heights[i]-heights[i-1]);
        int second_step = INT_MAX;
        if (i>1) second_step = dp[i-2] + abs(heights[i]-heights[i-2]);
        dp[i] = min(first_step, second_step);
    }
    return dp[n-1];
}

// int jump_tabulation_2(int n, vector<int>heights) {
//     int prev=0;
//     int prev2=0;
//     for(int i=1;i<n;i++) {
//         int fs = prev + abs(heights[i]-heights[i-1]);
//         int ss = INT_MAX;
//         if (i>1) ss = prev2 + abs(heights[i]-heights[i-2]);
//         int curr = min(fs,ss);
//         prev2=prev;
//         prev=curr;
//     }
//     return prev;
// }


// climbing stairs dp problem no. of ways u can jump to top
// you jump by one position or 2 position
// return total no. of ways
int climbing_stairs(int n) {
    if (n==0) return 1;
    if (n==1) return 1;
    int left = climbing_stairs(n-1);
    int right = climbing_stairs(n-2);
    return left+right;
}

int main() {

}