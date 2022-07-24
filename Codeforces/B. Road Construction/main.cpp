/*
 * Link : https://codeforces.com/problemset/problem/330/B
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    bool blocked[n+1] = {false};

    for(int i = 0; i < m; i++)
    {
        int c1, c2;

        cin >> c1 >> c2;

        blocked[c1] = true;
        blocked[c2] = true;

    }

    int not_blocked = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!blocked[i])
        {
            not_blocked = i;
            break;
        }
    }

    cout << n-1 << "\n";


    for(int i = 1; i <= n; i++)
    {
        if(i == not_blocked)
            continue;

        cout << not_blocked << " " << i << "\n";
    }

    return 0;
}