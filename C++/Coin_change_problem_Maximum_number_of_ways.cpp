#include<bits/stdc++.h>
using namespace std;

int coinChangeMaxWays(int *coin, int size, int rupee) {
    vector<vector<int> > dp(size+1, vector<int> (rupee+1, -1));
    for(int i=0; i<size+1; i++) {
        for(int j=0; j<rupee+1; j++) {
            if(i == 0) {
                dp[i][j] = 0;
            }
            if(j == 0) {
                dp[i][j] = 1;
            }
        }
    }
    for(int i=1; i<size+1; i++) {
        for(int j=1; j<rupee+1; j++) {
            if(coin[i-1] <= j) {
                dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[size][rupee];
}

int main() {
    int coin[] = {1, 2, 3};
    int rupee = 4;
    int size = sizeof(coin)/sizeof(coin[0]);
    cout << "No. of ways : " << coinChangeMaxWays(coin, size, rupee); // {1,1,1,1},{1,1,2},{2,2},{1,3}
    return 0;
}