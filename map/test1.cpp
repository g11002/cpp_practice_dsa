#include <iostream>
#include <unordered_set>
using namespace std;

// intersection of two array
void intersect(int a[], int b[], int m, int n) {
    unordered_set<int>set(b,b+n);
    for (int i=0;i<m;i++) {
        if (set.find(a[i]) != set.end()) {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

// union of the two array
void union_array(int a[], int b[], int m, int n) {
    unordered_set<int>res;
    for (int i=0;i<m;i++) res.insert(a[i]);
    for (int i=0;i<n;i++) res.insert(b[i]);
    for (auto i:res) cout << i << " ";
    cout << endl;
}

// pair sum with x
void pairWithSumX(int arr[], int n, int x) {
    unordered_set<int>s;
    for (int i=0;i<n;i++) {
        if (s.find(x-arr[i]) != s.end()) cout << "pair found" << endl;
        s.insert(arr[i]);
    }
}

int main() {
    int a[] = {10,20};
    int b[] = {20,30};
    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);
    intersect(a,b,m,n);
    union_array(a,b,m,n);
    int arr1[] = {3, 8, 4, 7, 6, 1};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int X = 14;
    pairWithSumX(arr1, n1, X);
    return 0;
}
