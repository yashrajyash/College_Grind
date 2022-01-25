#include<bits/stdc++.h>
using namespace std;

void lcs(string X, string Y, int m, int n, vector<vector<int> > &dp) {
    for(int i=0; i<m+1; i++) {
        for(int j=0; j<n+1; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(X[i-1] == Y[i-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
}

string scs(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int> > dp(m+1, vector<int> (n+1, -1));
    lcs(X, Y, m, n, dp);
    string ans;
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(X[i-1] == Y[j-1]) {
            ans.push_back(X[i-1]);
            i--; j--;
        } else if(dp[i][j-1] > dp[i-1][j]) {
            ans.push_back(Y[j-1]);
            j--;
        } else {
            ans.push_back(X[i-1]);
            i--;
        }
    }
    while(i > 0) {
        ans.push_back(X[i-1]);
        i--;
    }
    while(j > 0) {
        ans.push_back(Y[j-1]);
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string X = "HELLO";
    string Y = "GEEK";
    cout << "Shortest common supersequence is : " << scs(X, Y);
    return 0;
}

/* Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB" 
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest 
supersequence of X and Y */