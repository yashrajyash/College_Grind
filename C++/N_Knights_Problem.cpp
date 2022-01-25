#include<bits/stdc++.h>
using namespace std;

int ans = 0;

void display(int n, vector<vector<int> > &grid) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isSafe(int cr, int cc, int n, vector<vector<int> > &grid) {
    if(cr-2 >=0  && cc-1 >=0 && grid[cr-2][cc-1]) return false;
    if(cr-1 >=0  && cc-2 >=0 && grid[cr-1][cc-2]) return false;
    if(cr-1 >=0  && cc+2 < n  && grid[cr-1][cc+2]) return false;
    if(cr-2 >=0  && cc+1 < n  && grid[cr-2][cc+1]) return false;
    return true;
}

void nKnights(int cr, int cc, int count, int n, vector<vector<int> > &grid) {
    if(count == n) {
        display(n, grid);
        ans++;
        return;
    }
    for(int i=cr; i<n; i++) {
        for(int j=(i==cr)? cc:0; j<n; j++) {
            if(isSafe(i, j, n, grid)) {
                grid[i][j] = 1;
                nKnights(i, j+1, count+1, n, grid);
                grid[i][j] = 0;
            }
        }
    }
}

int main() {
    int t;
    int n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<vector<int> > grid(n, vector<int> (n, 0));
        nKnights(0, 0, 0, n, grid);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}