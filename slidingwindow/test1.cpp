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

// max in sliding window
// Input: arr = [4, 0, -1, 3, 5, 3, 6, 8], k = 3
// Output: [4, 3, 5, 5, 6, 8]
// Input: arr = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
// Output: [3, 3, 5, 5, 6, 7]
// brute force approach
vector<int> maxSlidingWindow(vector<int> &arr, int k) {
    int n=arr.size();
    vector<int>ans;
    for(int i=0;i<=n-k;i++) {
        int maxi=arr[i];
        for(int j=i;j<i+k;j++) {
            maxi=max(maxi,arr[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}
// optimal solution with sliding window and priority key max heap approach
vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    vector<int> result;
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < nums.size(); ++i) {
        // Add current element
        maxHeap.push({nums[i], i});
        // Remove elements - outside the window/previous elements where window has passed
        while (!maxHeap.empty() && maxHeap.top().second <= i - k) {
            maxHeap.pop();
        }
        // Append current max to result when window is ready
        if (i >= k - 1) {
            result.push_back(maxHeap.top().first);
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1, 3, 2, 6, 4, 8, 5};
    int k = 3;
    slidingWindowSum(arr, k);
    cout<<"Max sum sliding window: "<<maxSumSlidingWindow(arr,k)<<endl;
    return 0;
}
