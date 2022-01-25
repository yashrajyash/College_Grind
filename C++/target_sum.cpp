#include<bits/stdc++.h>
using namespace std;

int countSubsetSum(int *arr, int n, int sum) {
    vector<vector<int> > dp(n+1, vector<int> (sum+1, -1));
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<sum+1; j++) {
            if(i == 0) {
                dp[i][j] = 0;
            }
            if(j == 0) {
                dp[i][j] = 1;
            }
        }
    }
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {
            if(arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    int arr[] = {1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0, s = 3; // s = diff = s1 - s2
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    int s1 = (s+sum)/2;
    cout << "Total ways are : "
         << countSubsetSum(arr, n, s1);
    return 0;
}