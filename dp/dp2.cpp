#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// grid unique path given a matrix
// recursion approach
int func(int i, int j) {
    if (i==0 && j==0) return 1;
    if (i<0 || j<0) return 0;
    int up = func(i-1,j);
    int left = func(i,j-1);
    return up+left;
}

int uniquePaths(int m, int n) {
    return func(m-1,n-1);
}
//memoization approach
int func(int i, int j, vector<vector<int>>& dp){
    if (i == 0 && j == 0)  return 1;
    if (i < 0 || j < 0)  return 0;
    if (dp[i][j] != -1)  return dp[i][j];
    int up = func(i - 1, j, dp);
    int left = func(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return func(m-1,n-1, dp);
}
//tabulation approach
int func(int m, int n, vector<vector<int>>& dp){
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(i==0 && j==0) {
                dp[i][j]=1;
                continue;
            }
            int up=0;
            int left=0;
            if(i>0) {up=dp[i-1][j];}
            if(j>0) {left=dp[i][j-1];}
            dp[i][j]=up+left;
        }
    }
    return dp[m-1][n-1];
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return func(m,n,dp);
}
//unique path with the obstacle to avoid
//recursion approach
int func(int i, int j, vector<vector<int>> &matrix) {
    if(i==0 && j==0) return 1;
    if(i>0 && j>0 && matrix[i][j]==1) return 0;
    if(i<0 || j<0) return 0;
    int up=func(i-1,j,matrix);
    int left=func(i,j-1,matrix);
    return up+left;
}
int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    return func(m-1,n-1,matrix);
}
//memoization approach
int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
    if (i < 0 || j < 0 || matrix[i][j] == 1) return 0;
    else if(i == 0 && j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    int up = func(i - 1, j, matrix, dp);
    int left = func(i, j - 1, matrix, dp);
    return dp[i][j] = up + left;
}

int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<vector<int>>dp(m, vector<int>(n,-1));
    return func(m-1,n-1,matrix,dp);
}