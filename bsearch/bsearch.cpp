#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int b_search(int arr[], int n, int x) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid]>x) {
            high = mid -1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int bsearch_recursive(int arr[], int low, int high, int x) {
    if (low > high) { return -1; }
    int mid = (low+high)/2;
    if (arr[mid] == x) { return mid; }
    else if (arr[mid] > x) { return bsearch_recursive(arr,low,mid-1,x); }
    else { return bsearch_recursive(arr,mid+1,high,x); }
}

int firstOcc(int arr[], int n, int x) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if (arr[mid]>x) {
            high=mid-1;
        } else if (arr[mid]<x) {
            low = mid+1;
        } else {
            if (mid==0 || arr[mid-1]!=arr[mid]) {
                return mid;
            } else {
                high = mid-1;
            }
        }
    }
    return -1;
}

int lastOcc(int arr[], int n, int x) {
    int low = 0, high = n-1;
    while(low<=high) {
        int mid = (low+high)/2;
        if (arr[mid]>x) { high=mid-1; }
        else if (arr[mid]<x) { low=mid+1; }
        else {
            if (arr[mid-1] || arr[mid+1]!=arr[mid]) {
                return mid;
            } else {
                low = mid+1;
            }
        }
    }
    return -1;
}

int sqrt_x(int x) {
    int low = 1, high = x, ans = -1;
    while(low<=high) {
        int mid = (low+high)/2;
        int mids = mid*mid;
        if(mids == x) {return mid;}
        else if (mids > x) {high = mid-1;}
        else {low=mid+1;ans=mid;}
    }
    return ans;
}

bool is_pair(int arr[], int n, int x) {
    int i=0, j=n-1;
    while(i<=j) {
        if(arr[i]+arr[j] == x) return true;
        else if (arr[i]+arr[j]>x) j--;
        else i++;
    }
    return false;
}

int main() {
    int arr[] = {10,20,30,40,50,60}, n=6;
    int x = 20;
    cout << b_search(arr,n,x) << endl;
    cout << bsearch_recursive(arr,0,n-1,x) << endl;
    int arr1[] = {5,10,10,10,20}, n1=5;
	int x1 = 10;
	cout << firstOcc(arr1, n1, x1) << endl;
    int arr2[] = {5,10,10,10,10,20,20}, n2=7;
	int x2 = 10;
    cout << lastOcc(arr2,n2,x2) << endl;
    int x3 = 10;
    cout << sqrt_x(x3) << endl;
    // 2 pointer approach
    // find if there is a pair with sum x in a sorted array
    int x4 = 17;
    int n3 = 5;
    int arr3[] = {2,5,8,12,30};
    cout << is_pair(arr3,n3,x4) << endl;
    return 0;
}