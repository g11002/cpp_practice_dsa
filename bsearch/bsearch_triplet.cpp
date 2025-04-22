#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int arr[], int arr_size, int sum) {
    sort(arr, arr+arr_size);
    for(int i=0;i<arr_size-2;i++) {
        int l=i+1;
        int r=arr_size-1;
        while(l<r) {
            if (arr[i]+arr[l]+arr[r]==sum) {
                printf("Triplet is %d, %d, %d",arr[i],arr[l],arr[r]);
                return true;
            } else if (arr[i] + arr[l] + arr[r] < sum) {
                l++;
            } else {
                r--;
            }
        }
    }
    return false;
}

int main() {
    int A[] = { 1, 4, 45, 6, 10, 8 };
	int sum = 22;
	int arr_size = sizeof(A) / sizeof(A[0]);
	cout << find3Numbers(A, arr_size, sum) << endl;
    return 0;
}