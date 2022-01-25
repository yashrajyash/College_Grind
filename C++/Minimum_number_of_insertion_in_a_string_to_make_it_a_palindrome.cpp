#include<bits/stdc++.h>
using namespace std;

#define len 7 // X length

int static dp[len+1][len+1];

int lcs(string X, string Y, int m, int n) {
    if(m == 0 || n == 0) {
        return 0;
    }
    if(dp[m][n] != -1) {
        return dp[m][n];
    }
    if(X[m-1] == Y[n-1]) {
        return dp[m][n] = 1 + lcs(X, Y, m-1, n-1);
    }
    return dp[m][n] = max(lcs(X, Y, m-1, n), lcs(X, Y, m, n-1));
}

int main() {
    string X = "aebcbda";
    string Y = X;
    reverse(Y.begin(), Y.end());
    int n = X.length();
    memset(dp, -1, sizeof(dp));
    cout << "Min. no. insertion : " << n - lcs(X, Y, n, n);
    return 0;
}

// min. of insertion = min. of deletion