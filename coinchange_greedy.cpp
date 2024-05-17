#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void mincoin(vector<int> &coin, int sum)
{
    sort(coin.begin(),coin.end(),greater<int>());
    int result = 0;

    vector <int> res;

    for (size_t i = 0; i < coin.size(); i++)
    {
        while (sum >= coin[i])
        {
            result++;
            sum -= coin[i];
            res.push_back(coin[i]);
        }
    }

    cout << "Minimum number of coins = " << result << endl;
    cout << "Coins are = " ; for (auto it:res) cout << it << " ";
    cout << endl;
    
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