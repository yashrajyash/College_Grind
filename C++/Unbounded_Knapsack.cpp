#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int *wt, int *val, int n, int W) {
    vector<vector<int> > dp(n+1, vector<int> (W+1, -1));
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<W+1; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            if(wt[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]] , dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int weight[] = {1, 50};
    int value[] = {1, 30};
    int W = 100;
    int n = sizeof(value)/sizeof(value[0]);
    cout << "The maximum amount that could make up this quantity exactly : " << unboundedKnapsack(weight, value, n, W);
    return 0;
}