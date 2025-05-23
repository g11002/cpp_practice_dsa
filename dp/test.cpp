#include <iostream>
#include <string.h>
using namespace std;

int fib(int n) {
    if (n==0 || n==1) {
        return n;
    } else {
        return fib(n-1)+fib(n-2);
    }
}

int memo[1000000];
int fib1(int n)
{
    if(memo[n]==-1) {
        int res;
        if (n==0 || n==1)
            return n;
        else {
            res=fib1(n-1)+fib1(n-2);
        }
        memo[n]=res;
    }
    return memo[n];
}

int main() {
    int n=10;
    for(int i=0;i<n;i++) {
        cout << fib(i) << " ";
    }
    cout << endl;
    
    int n1=20;
    memset(memo,-1,sizeof(n1));
    for(int i=0;i<20;i++) {
        cout << fib1(i) << " ";
    }
    // cout<<fib1(20)<<endl;
    cout << endl;
    return 0;
}