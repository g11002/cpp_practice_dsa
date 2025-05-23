#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <algorithm>
using namespace std;

// Given an integer n, there is a staircase with n steps, starting from the 0th step.
// Determine the number of unique ways to reach the nth step, given that each move can be either 1 or 2 steps at a time.
// climbing stairs
int climbStairs_rec(int n) {
    if (n==0) return 1;
    if (n==1) return 1;
    int onestep = climbStairs_rec(n-1);
    int secondstep = climbStairs_rec(n-2);
    return onestep+secondstep;
}
//memoization approach
int func(int n, vector<int> &dp) {
    // Base condition
    if (n <= 1) {
        return 1;
    }
    // Check if the subproblem is already solved
    if (dp[n] != -1) {
        return dp[n];
    }
    // Return the calculated value
    return dp[n] = func(n-1, dp) + func(n-2, dp);
}
int climbStairs_memo(int n) {
    vector<int>dp(n+1,-1);
    return func(n, dp);
}
//tabulation approach
int climbStairs_tab(int n) {
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Frog Jump
// A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step.
// To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference.
// The frog can jump from any step either one or two steps, provided it exists.
// Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.
// recursion approach
int func(vector<int> heights, int ind) {
    if(ind==0) return 0;
    int jumpone = func(heights, ind-1) + abs(heights[ind]-heights[ind-1]);
    int jumptwo = INT_MAX;
    if(ind>1) {
        jumptwo = func(heights, ind-2) + abs(heights[ind]-heights[ind-2]);
    }
    return min(jumpone,jumptwo);
}
int frogJump(vector<int>& heights) {
    int n=heights.size();
    return func(heights,n-1);
}
// memoization approach
int solve(int ind, vector<int>heights, vector<int>dp) {
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpOne=solve(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int jumpTwo=INT_MAX;
    if(jumpTwo>1) {
        jumpTwo=solve(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    }
    return dp[ind]=min(jumpOne,jumpTwo);
}
int frogJump(vector<int>& heights) {
    int n=heights.size();
    vector<int>dp(n+1,-1);
    return solve(n-1,heights,dp);
}
// tabulation approach
int frogJump(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, -1);
    dp[0]=0;
    for(int ind=1;ind<n;ind++) {
        int jumpOne = dp[ind-1] + abs(heights[ind]-heights[ind-1]);
        int jumpTwo = INT_MAX;
        if (ind>1) {
            jumpTwo = dp[ind-2] + abs(heights[ind]-heights[ind-2]);
        }
        dp[ind]=min(jumpOne,jumpTwo);
    }
    return dp[n-1];
}

// frog jump with k distance
// A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.
// To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference.
// The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists.
// Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.
// recursion approach
int func(int ind, vector<int>heights, int k) {
    if(ind==0) {
        return 0;
    }
    int mmstep=INT_MAX;
    for(int j=1;j<=k;j++) {
        if(ind-j>=0) {
            int jump=func(ind-j,heights,k)+abs(heights[ind]-heights[ind-j]);
            mmstep=min(jump,mmstep);
        }
    }
    return mmstep;
}
int frogJump(vector<int>& heights, int k) {
    int ind=heights.size()-1;
    return func(ind, heights, k);
}
// memoization approach
int func(int ind, vector<int>&heights, int k, vector<int>&dp) {
    if(ind==0) {
        return 0;
    }
    if(dp[ind]!=-1) {
        return dp[ind];
    }
    int mmstep=INT_MAX;
    for(int j=1;j<=k;j++) {
        if(ind-j>=0) {
            int jump=func(ind-j,heights,k,dp)+abs(heights[ind]-heights[ind-j]);
            mmstep=min(jump,mmstep);
        }
    }
    return dp[ind]=mmstep;
}
int frogJump(vector<int>& heights, int k) {
    int ind=heights.size()-1;
    vector<int>dp(ind+1,-1);
    return func(ind, heights, k, dp);
}
// tabulation approach
int frogJump(vector<int>& heights, int k) {
    int ind=heights.size();
    vector<int>dp(ind+1,-1);
    dp[0]=0;
    for(int i=1;i<ind;i++) {
        int mmsteps=INT_MAX;
        for(int j=1;j<=k;j++) {
            if(i-j>=0) {
                int jump=dp[i-j]+abs(heights[i]-heights[i-j]);
                mmsteps=min(jump,mmsteps);
            }
        }
        dp[i]=mmsteps;
    }
    return dp[ind-1];
}

// Maximum sum of non adjacent elements
// Input: nums = [1, 2, 4]
// Output: 5
// Explanation: [1, 2, 4], the underlined elements are taken to get the maximum sum.
// Input: nums = [2, 1, 4, 9]
// Output: 11
// Explanation: [2, 1, 4, 9], the underlined elements are taken to get the maximum sum.
// recursion approach
int func(int ind, vector<int>&arr) {
    if(ind==0) {return arr[ind];}
    if(ind<0) {return 0;}
    int pick = arr[ind]+func(ind-2,arr);
    int notpick = 0 + func(ind-1,arr);
    return max(pick,notpick);
}
int nonAdjacent(vector<int>& nums) {
    int ind=nums.size()-1;
    return func(ind, nums);
}
//memoisation approach
int func(int ind, vector<int>&arr, vector<int>&dp) {
    if(dp[ind]!=-1) {return dp[ind];}
    if(ind==0) {return arr[ind];}
    if(ind<0) {return 0;}
    int pick = arr[ind]+func(ind-2,arr,dp);
    int notpick = 0 + func(ind-1,arr,dp);
    return dp[ind]=max(pick,notpick);
}

int nonAdjacent(vector<int>& nums) {
    int ind=nums.size()-1;
    vector<int>dp(ind+1,-1);
    return func(ind, nums, dp);
}
//tabulation approach
int nonAdjacent(vector<int>& nums) {
    int ind=nums.size();
    vector<int>dp(ind,0);
    dp[0]=nums[0];
    for(int i=1;i<ind;i++) {
        int pick=nums[i];
        if(i>1) {
            pick+=dp[i-2];
        }
        int notpick=dp[i-1];
        dp[i]=max(pick,notpick);
    }
    return dp[ind-1];
}
// house robber problem
// recursion approach
int func(int ind, vector<int>&arr) {
    if(ind==0) return arr[ind];
    if(ind<0) return 0;
    int pick=arr[ind]+func(ind-2,arr);
    int notpick=0+func(ind-1,arr);
    return max(pick,notpick);
}
int houseRobber(vector<int>& money) {
    int n=money.size();
    vector<int>arr1;
    vector<int>arr2;
    if(n==1) {
        return money[0];
    }
    for(int i=0;i<n;i++) {
        if(i!=n-1) arr1.push_back(money[i]);
        if(i!=0) arr2.push_back(money[i]);
    }
    int ans1=func(arr1.size()-1,arr1);
    int ans2=func(arr2.size()-1,arr2);
    return max(ans1,ans2);
}
// memoization approach
int func(int ind, vector<int>&arr, vector<int>&dp) {
    if(dp[ind]!=-1) return dp[ind];
    if(ind==0) return arr[ind];
    if(ind<0) return 0;
    int pick=arr[ind]+func(ind-2,arr,dp);
    int notpick=0+func(ind-1,arr,dp);
    return dp[ind]=max(pick,notpick);
}
int houseRobber(vector<int>& money) {
    int n=money.size();
    vector<int>dp1(n,-1);
    vector<int>dp2(n,-1);
    vector<int>arr1;
    vector<int>arr2;
    if(n==1) {
        return money[0];
    }
    for(int i=0;i<n;i++) {
        if(i!=n-1) arr1.push_back(money[i]);
        if(i!=0) arr2.push_back(money[i]);
    }
    int ans1=func(arr1.size()-1,arr1,dp1);
    int ans2=func(arr2.size()-1,arr2,dp2);
    return max(ans1,ans2);
}
// tabulation approach
int func(vector<int> &nums){
    int ind = nums.size();
    vector<int> dp(ind, 0);
    dp[0] = nums[0];
    for (int i = 1; i < ind; i++) {
        int pick = nums[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = dp[i - 1];
        dp[i] = max(pick, nonPick);
    }
    return dp[ind-1];
}
int houseRobber(vector<int>& money) {
    int n = money.size();
    vector<int> arr1;
    vector<int> arr2;
    if(n==1)
        return money[0];
    for(int i=0; i<n; i++){
        if(i!=n-1) arr1.push_back(money[i]);
        if(i!=0) arr2.push_back(money[i]);
    }
    int ans1 = func(arr1);
    int ans2 = func(arr2);
    return max(ans1,ans2);
}

//ninja training
//recursion approach
int func(int day, int last, vector<vector<int>> &points) {
        if (day==0) {
        int maxi=0;
        for (int i=0;i<=2;i++) {
            if (i!=last)  maxi=max(maxi,points[0][i]);
        }
        return maxi;
    }
    int maxi = 0;
    for (int i=0;i<=2;i++) {
        if (i!=last) {
            int activity=points[day][i]+func(day-1,i,points);
            maxi=max(maxi,activity);
        }
    }
    return maxi;
}
int ninjaTraining(vector<vector<int>>& matrix) {
    int day = matrix.size()-1;
    int last = 3;
    return func(day, last, matrix);
}
//memoization approach
int func(int day, int last, vector<vector<int>>&matrix, vector<vector<int>>&dp) {
    if(dp[day][last]!=-1) return dp[day][last];
    if(day==0) {
        int maxi=0;
        for(int i=0;i<=2;i++) {
            if(i!=last) maxi=max(maxi,matrix[0][i]);
        }
        return dp[day][last]=maxi;
    }
    int maxi=0;
    for(int i=0;i<=2;i++) {
        if(i!=last) {
            int activity=matrix[day][i]+func(day-1,i,matrix,dp);
            maxi=max(maxi,activity);
        }
    }
    return dp[day][last]=maxi;
}

int ninjaTraining(vector<vector<int>>& matrix) {
    int day = matrix.size();
    int last=3;
    vector<vector<int>>dp(day, vector<int>(4,-1));
    return func(day-1,last,matrix,dp);
}




int main() {
    return 0;
}