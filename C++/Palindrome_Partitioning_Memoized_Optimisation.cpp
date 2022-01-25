#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

bool isPalindrome(string &str, int i, int j) {
    while(i <= j) {
        if(str[i] != str[j]) {
            return false;
        }
        i++; j--;
    }
    return true;
}

int minPalPartion(string &str, int i, int j) {
    if(i >= j || isPalindrome(str, i, j)) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++) {
        int left, right;
        if(dp[i][k] != -1) {
            left = dp[i][k];
        } else {
            left = minPalPartion(str, i, k);
        }
        if(dp[k+1][j] != -1) {
            right = dp[k+1][j];
        } else {
            right = minPalPartion(str, k+1, j);
        }
        int tmp = left + 1 + right;
        mn = min(mn, tmp);
    }
    return dp[i][j] = mn;
}

int main() {
    string str = "ababbbabbababa";
    memset(dp, -1, sizeof(dp));
    cout << "Min cuts needed for " <<
      "Palindrome Partitioning is " << 
      minPalPartion(str, 0, str.length() - 1) << endl;
    return 0;
}