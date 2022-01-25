#include <iostream>
#include <vector>
using namespace std;

int knapSack(int *weight, int *value, int n, int W, vector<vector<int>> &dp)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (weight[n - 1] <= W)
    {
        return dp[n][W] = max(value[n - 1] + knapSack(weight, value, n - 1, W - weight[n - 1], dp), knapSack(weight, value, n - 1, W, dp));
    }
    return dp[n][W] = knapSack(weight, value, n - 1, W, dp);
}

int main()
{
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(value) / sizeof(value[0]);
    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    int maxProfit = knapSack(weight, value, n, W, dp);
    cout << "Max profit : " << maxProfit;
    return 0;
}