#include<bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int m, int n) {
    int dp[m+1][n+1];
    for(int i=0; i<m+1; i++) {
        for(int j=0; j<n+1; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(X[i-1] == Y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

string reverseStr(string x){
    string y = x;
    reverse(y.begin(), y.end());
    return y;
}

int main()
{
    string x = "agbcbad";
    string y = reverseStr(x);
    cout<< "X: "<<x<<endl;
    cout<< "Y: "<<y<<endl;


    int lengthOfThePalindromeSubsequence = lcs(x, y, x.length(), y.length());
    cout<< "The length of the palindrome subsequence is "<<lengthOfThePalindromeSubsequence<<endl;

    return 0;
}