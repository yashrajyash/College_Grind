#include <iostream>
using namespace std;

int knapSack(int *weight, int *value, int n, int W) {
    if(n == 0 || W == 0) {
        return 0;
    }
    if(weight[n-1] <= W) {
        return max(value[n-1] + knapSack(weight, value, n-1, W-weight[n-1]), knapSack(weight, value, n-1, W));
    }
    return knapSack(weight, value, n-1, W);
}

int main()
{
    int value[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(value) / sizeof(value[0]);
    int maxProfit = knapSack(weight, value, n, W);
    cout << "Max profit : " << maxProfit;
    return 0;
}