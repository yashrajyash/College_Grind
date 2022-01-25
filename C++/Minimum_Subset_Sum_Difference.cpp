#include<bits/stdc++.h>
using namespace std;

int findMin(int *arr, int n, int sum) { // sum = range
    vector<vector<bool> > dp(n+1, vector<bool> (false, sum+1));
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<sum+1; j++) {
            if(i == 0) {
                dp[i][j] = false;
            }
            if(j == 0) {
                dp[i][j] = true;
            }
        }
    } // i->n, j->sum
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {
            if(arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int> subsetsum;
    for(int i=0; i<=sum/2; i++) {
        if(dp[n][i]) {
            subsetsum.push_back(i);
        }
    }
    int minm = INT_MAX;
    for(int i=0; i<subsetsum.size(); i++) {
        minm = min(minm, sum - 2*subsetsum[i]);
    }
    return minm;
}

int main() {
    int arr[] = { 3, 1, 4, 2, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    cout << "The minimum difference between two sets is "
         << findMin(arr, n, sum);
    return 0;
}