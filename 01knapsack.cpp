#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int knapsack(int knapsack_size, int weights[], int profits[], int items)
{
    if (items == 0 || knapsack_size == 0)
    {
        return 0;
    }
    else
    {
        if (weights[items - 1] > knapsack_size)
        {
            return knapsack(knapsack_size, weights, profits, items - 1);
        }
        else
        {
            return max(profits[items - 1] + knapsack(knapsack_size - weights[items - 1], weights, profits, items - 1),
                       knapsack(knapsack_size, weights, profits, items - 1));
        }
    }
}

void soln()
{
    int knapsack_size = 5;
    int items = 4;
    int weights[] = {5, 7, 6, 10};
    int profits[] = {10, 20, 30, 40};

    cout << knapsack(knapsack_size, weights, profits, items) << endl;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int __;
    cin >> __;
    while (__-- != 0)
        soln();

    return 0;
}