#include<iostream>
#include<vector>
using namespace std;

int findCnt(int *arr, int n, int sum) {
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
    int arr[] = { 3, 3, 3, 3 };
    int n = sizeof(arr) / sizeof(int);
    int sum = 6;
  
    cout << findCnt(arr, n, sum);
    return 0;
}