#include <iostream>
#include <vector>
using namespace std;

int knapSack(int *weight, int *value, int n, int W)
{
    /* if(n == 0 || W == 0) {
        return 0;
    }
    if(weight[n-1] <= W) {
        return max(value[n-1] + knapSack(weight, value, n-1, W-weight[n-1]), knapSack(weight, value, n-1, W));
    }
    return knapSack(weight, value, n-1, W); */

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

    for(int i=0; i<n+1; i++) {
        for(int j=0; j<W+1; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            if(weight[i-1] <= j) {
                dp[i][j] = max(value[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(value) / sizeof(value[0]);
    
    int maxProfit = knapSack(weight, value, n, W);
    cout << "Max profit : " << maxProfit;
    return 0;
}