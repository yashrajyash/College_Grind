#include<bits/stdc++.h>
using namespace std;

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
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++) {
        int tmp = minPalPartion(str, i, k) + 1 + minPalPartion(str, k+1, j);
        mn = min(mn, tmp);
    }
    return mn;
}

int main() {
    string str = "ababbbabbababa";
    cout << "Min cuts needed for " <<
      "Palindrome Partitioning is " << 
      minPalPartion(str, 0, str.length() - 1) << endl;
    return 0;
}