#include<bits/stdc++.h>
using namespace std;

#define M 6 // == m
#define N 7 // == n

int static memo[M+1][N+1];

int lcs(string x, string y, int m, int n) {
    if(m == 0 || n == 0) {
        return 0;
    }
    if(memo[m][n] != -1) {
        return memo[m][n];
    }
    if(x[m-1] == y[n-1]) {
        return memo[m][n] = 1+lcs(x, y, m-1, n-1);
    }
    return memo[m][n] = max(lcs(x, y, m, n-1), lcs(x, y, m-1, n));
}

int main() {
    string x = "AGGTAB";
    string y = "GXTXAYB";
    int m = x.length();
    int n = y.length();
    memset(memo, -1, sizeof(memo));
    cout<<"Length of LCS is "<< lcs(x, y, m, n);
    return 0;
}