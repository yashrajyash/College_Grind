#include <bits/stdc++.h>
using namespace std;

int minNoCoins(int *coin, int n, int sum)
{
    vector<vector<int>> t(n + 1, vector<int>(sum + 1, -1));
    
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
            {
                t[i][j] = 0;
            }
            else if (i == 0)
            {
                t[i][j] = INT_MAX - 1;
            }
        }
    }

    for (int i = 1; i <= 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (j % coin[0] == 0 && j / coin[0] == 1)
            {
                t[i][j] = 1;
            }
            else
            {
                t[i][j] = INT_MAX - 1;
            }
        }
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                t[i][j] = min(1 + t[i][j - coin[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}

int main()
{
    int coin[] = {25, 10, 5};
    int rupee = 30;
    int size = sizeof(coin) / sizeof(coin[0]);
    cout << "Minimum no. of coins : " << minNoCoins(coin, size, rupee);
    return 0;
}