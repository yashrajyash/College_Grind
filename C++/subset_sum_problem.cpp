#include<iostream>
#include<vector>
using namespace std;

bool subsetSum(int *set, int sum, int n) {
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
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<sum+1; j++) {
            if(set[i-1] <= j) {
                dp[i][j] = dp[i-1][j-set[i-1]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    
    bool isFound = subsetSum(set, sum, n);
    if (isFound)
         cout <<"Found a subset with given sum";
    else
        cout <<"No subset with given sum";
    return 0;
}