#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void LIS(vector<int> &v)
{
    int dp[4][1000];
    memset(dp, 0, sizeof(dp));

    int res = 0;
    for (int i = 1; i < v.size() + 1; i++)
    {
        dp[0][i] = i;
        dp[1][i] = v[i - 1];
        for (int j = 0; j < i; j++)
        {
            if (dp[1][j] < dp[1][i])
            {
                dp[2][i] = max(dp[2][i], dp[2][j] + 1);
                res = max(res, dp[2][i]);
                if (dp[2][i] == dp[2][j] + 1)
                {
                    dp[3][i] = max(dp[3][i], j);
                }
            }
        }
    }

    // dp table:-
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < v.size() + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // retrive seq :-
    int index = 0;
    for (size_t i = 0; i < v.size() + 1; i++)
    {
        if (dp[2][i] == res)
        {
            index = i;
        }
    }
    vector<int> seq;
    while (index != 0)
    {
        seq.push_back(dp[1][index]);
        index = dp[3][index];
    }
    reverse(seq.begin(), seq.end());

    
    cout << "Longest increasing seq length = " << res << endl;
    cout << "seq = "; for (auto it : seq) cout << it << " ";
    cout << endl;
}

void soln()
{
    vector<int> v = {3,2,5,3,7,11,8,10,13,6};
    LIS(v);
    // examples {3,2,5,3,7,11,8,10,13,6}{1,5,2,6,7,3,9}{3, 10, 2, 1, 20}
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