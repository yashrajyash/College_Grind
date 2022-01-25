#include<bits/stdc++.h>
using namespace std;

int memo[50][50];

int eggDrop(int f, int e) {
    if(memo[f][e] != -1) {
        return memo[f][e];
    }
    if(f == 0 || f == 1) {
        return f;
    }
    if(e == 1) {
        return f;
    }
    int mn = INT_MAX;
    for(int k=1; k<=f; k++) {
        int low, high;
        if(memo[k-1][e-1] != -1) {
            low = memo[k-1][e-1];
        } else {
            low = eggDrop(k-1, e-1);
        }
        if(memo[f-k][e] != -1) {
            high = memo[f-k][e];
        } else {
            high = eggDrop(f-k, e);
        }
        int tmp = 1 + max(low, high);
        mn = min(mn, tmp);
    }
    return memo[f][e] = mn;
}

int main() {
	int floors = 4, eggs = 2;
	// cin >> floors >> eggs;
    memset(memo, -1, sizeof(memo));
	cout<<"number of trials when number of eggs is " << eggs;
	cout<<" and number of floors is " << floors;
	cout<<": "  << eggDrop(floors,eggs);
	return 0;
}