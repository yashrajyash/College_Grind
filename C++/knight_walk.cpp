#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int x_move[] = {-2, -2, -1, -1, 2, 2, 1, 1};
int y_move[] = {1, -1, 2, -2, 1, -1, 2, -2};

void display(int n, vector<vector<int> > &board) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << board[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

bool isSafe(int i, int j, int n, vector<vector<bool> > &isVisited) {
    return i<n && i>=0 && j<n && j>=0 && isVisited[i][j] == false;
}

void knight_walk(int i, int j, int n, vector<vector<int> > &board, vector<vector<bool> > &isVisited, int steps) {
    if(steps == n*n-1) {
        board[i][j] = steps;
        display(n, board);
        return;
    }
    if(steps >= n*n) {
        return;
    }
    board[i][j] = steps;
    isVisited[i][j] = 1;
    for(int k=0; k<8; k++) {
        int x = i + x_move[k];
        int y = j + y_move[k];
        if(isSafe(x, y, n, isVisited)) {
            knight_walk(x, y, n, board, isVisited, steps+1);
        }
    }
    isVisited[i][j] = 0;
    board[i][j] = -1;
}

int main() {
    IOS
    int n, steps = 0;
    cin >> n;
    cout << "\n";
    vector<vector<int> > board(n, vector<int> (n, -1));
    vector<vector<bool> > isVisited(n, vector<bool> (n, false));
    knight_walk(0, 0, n, board, isVisited, steps);
    return 0;
}