#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return;
}

void selectionSort(int arr[], int n) {
    for(int i=0;i<n;i++) {
        int tmp = i;
        for(int j=i+1;j<n;j++) {
            if (arr[tmp]>arr[j]) {
                tmp=j;
            }
        }
        swap(arr[i],arr[tmp]);
    }
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return;
}

void iSort(int arr[], int n) {
    for(int i=1;i<n;i++) {
        int tmp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>tmp) {
            // arr[j+1]=arr[j];
            swap(arr[j+1],arr[j]);
            j--;
        }
    }
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return;
}

void merge(int a[], int b[], int m, int n){
    int i=0,j=0;
    while(i<m && j<n){
        if(a[i]<b[j])
            cout<<a[i++]<<" ";
        else
            cout<<b[j++]<<" ";
    }
    while(i<m)
        cout<<a[i++]<<" ";
    while(j<n)
        cout<<b[j++]<<" ";    
}

int main() {
    int arr[] = {2, 1, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << endl;
    selectionSort(arr,n);
    cout << endl;
    iSort(arr,n);
    cout << endl;
    int a[]={10,15,20,40};
    int b[]={5,6,6,10,15};
	int m1 = sizeof(a)/sizeof(a[0]);
	int n1 = sizeof(b)/sizeof(b[0]);
	merge(a,b,m1,n1);
    cout << endl;
    return 0;
}