#include<bits/stdc++.h>
using namespace std;

int shortestSuperSequence(string x, string y, int m, int n) {
    int dp[m+1][n+1];
    for(int i=0; i<m+1; i++) {
        for(int j=0; j<n+1; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(x[i-1] == y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return m+n-dp[m][n];
}

int main() {
    string x = "AGGTAB";
    string y = "GXTXAYB";
    int m = x.length();
    int n = y.length();
    cout << "Length of the shortest supersequence is "
         << shortestSuperSequence(x, y, m, n) << endl;
    return 0;
}