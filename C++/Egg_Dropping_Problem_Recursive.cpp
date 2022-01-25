#include<bits/stdc++.h>
using namespace std;

int eggDrop(int f, int e) {
    if(f == 0 || f == 1) {
        return f;
    }
    if(e == 1) {
        return f;
    }
    int mn = INT_MAX;
    for(int k=1; k<=f; k++) {
        int tmp = 1 + max(eggDrop(k-1, e-1), eggDrop(f-k, e));
        mn = min(mn, tmp);
    }
    return mn;
}

int main() {
	int floors = 4, eggs = 2;
	// cin >> floors >> eggs;
	cout<<"number of trials when number of eggs is " << eggs;
	cout<<" and number of floors is " << floors;
	cout<<": "  << eggDrop(floors,eggs);
	return 0;
}