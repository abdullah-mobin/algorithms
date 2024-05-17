#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void mincoin(vector<int> &coin, int sum)
{
    int dp[coin.size() + 1][sum + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= sum; i++) dp[0][i] = i;

    for (size_t i = 1; i <= coin.size(); i++)
    {
        for (size_t j = 0; j <= sum; j++)
        {
            if (coin[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coin[i - 1]]);
            }
        }
    }

    // dp table result :-
    for (size_t i = 0; i <= coin.size(); i++)
    {
        for (size_t j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Minimum number of coins = " << dp[coin.size()][sum] << endl;
}

void soln()
{
    vector<int> coin = {1, 5, 6, 9};
    int sum = 10;
    mincoin(coin, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int __;
    cin >> __;
    while (__-- != 0)
        soln();

    return 0;
}