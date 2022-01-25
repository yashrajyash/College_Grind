#include<bits/stdc++.h>
using namespace std;

string longestRepeatedSubSeq(string str) {
    int n = str.length();
    vector<vector<int> > dp(n+1, vector<int> (n+1, -1));
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<n+1; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if(str[i-1] == str[j-1] && i != j) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    // return dp[n][n]; // return length of an longestRepeatedSubSeq
    string ans;
    int i = n, j = n;
    while(i > 0 && j > 0) {
        if(dp[i-1][j-1] + 1 == dp[i][j]) {
            ans.push_back(str[i-1]);
            i--; j--;
        } else if(dp[i][j-1] > dp[i-1][j]) {
            j--;
        } else {
            i--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string str = "AABEBCDD";
    cout << longestRepeatedSubSeq(str);
    return 0;
}