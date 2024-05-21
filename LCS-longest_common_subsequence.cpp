#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void LCS(string str1, string str2)
{
    int dp[str1.size() + 1][str2.size() + 1];

    for (size_t i = 0; i <= str1.size(); i++)
    {
        for (size_t j = 0; j <= str2.size(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << "Longest lenth = " << dp[str1.size()][str2.size()] << endl;
    // print dp :=
    // for (size_t i = 0; i <= str1.size(); i++)
    // {
    //     for (size_t j = 0; j <= str2.size(); j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // print sequence :=
    int id = dp[str1.size()][str2.size()];
    string res = string(id, '\0');
    int i = str1.size();
    int j = str2.size();
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            res[id - 1] = str1[i - 1];
            i--, j--, id--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << res << endl;
}

void soln()
{
    string str1 = "habijabi";
    string str2 = "kikhabi";
    LCS(str1, str2);
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