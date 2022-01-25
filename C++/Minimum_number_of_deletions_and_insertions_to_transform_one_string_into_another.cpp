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
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

void printMinDelAndInsert(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
 
    int len = lcs(str1, str2, m, n);
 
    cout << "Minimum number of deletions = " << (m - len)
         << endl;
 
    cout << "Minimum number of insertions = " << (n - len)
         << endl;
}

int main()
{
    string str1 = "heap";
    string str2 = "pea";
   
      // Function Call
    printMinDelAndInsert(str1, str2);
    return 0;
}