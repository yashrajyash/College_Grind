#include<iostream>
#include<vector>
using namespace std;

bool subsetSum(int *arr, int n, int sum) {
    vector<vector<bool> > dp(n+1, vector<bool> (sum+1, false));
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<sum+1; j++) {
            if(i == 0) {
                dp[i][j] = false;
            }
            if(j == 0) {
                dp[i][j] = true;
            }
        }
    }
    // n, sum => i, j
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {
            if(arr[i-1] <= j) {
                 dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    int arr[] = { 3, 1, 5, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    if(sum % 2 != 0) {
        cout << "False";
    } else {
        if(subsetSum(arr, n, sum/2)) {
            cout << "True";
        } else {
            cout << "False";
        }
    }
    return 0;
}