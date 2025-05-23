#include<bits/stdc++.h>
using namespace std;

void slidingWindowSum(const vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0;
    // Calculate the sum of the initial window
    for (int i = 0; i < k; ++i) {
        sum += arr[i];
    }
    // Print the sum of the first window
    cout << "Sum of window 1: " << sum << endl;
    // Slide the window across the array
    for (int i = k; i < n; ++i) {
        sum = sum - arr[i - k] + arr[i]; // Update the sum
        cout << "Sum of window " << i - k + 2 << ": " << sum << endl;
    }
}
int maxSumSlidingWindow(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];  // sum of first window
    }
    int maxSum = windowSum;
    // Slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];  // add next, remove first
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
int main() {
    vector<int> arr = {1, 3, 2, 6, 4, 8, 5};
    int k = 3;
    slidingWindowSum(arr, k);
    cout<<"Max sum sliding window: "<<maxSumSlidingWindow(arr,k)<<endl;
    return 0;
}
