#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int MatrixChainOrder(int *arr, int i, int j) {
    if(i >= j) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++) {
        int tmp = MatrixChainOrder(arr, i, k) + MatrixChainOrder(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        mn = min(mn, tmp);
    }
    return dp[i][j] = mn;
}

int main() {
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Ai = arr[i-1] x arr[i]
    memset(dp, -1, sizeof(dp));
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 1, n - 1);
    return 0;
}