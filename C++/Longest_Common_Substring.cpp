#include<bits/stdc++.h>
using namespace std;

int LCSubStr(string X, string Y, int m, int n) {
    int ans = INT_MIN;
    vector<vector<int> > dp(m+1, vector<int> (n+1, -1));
    for(int i=0; i<m+1; i++) {
        for(int j=0; j<n+1; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<m+1; i++) {
        for(int j=1; j<n+1; j++) {
            if(X[i-1] == Y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(dp[i][j], ans);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main()
{
    char X[] = "GeeksforGeeks";
    char Y[] = "GeeksQuiz";
 
    int m = strlen(X);
    int n = strlen(Y);
 
    cout << "Length of Longest Common Substring is "
         << LCSubStr(X, Y, m, n);
    return 0;
}