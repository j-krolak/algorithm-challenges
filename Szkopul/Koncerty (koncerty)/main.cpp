#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e7 + 10;

int koncerty[MAXN];

int main()
{       
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++)
        {
                cin >> koncerty[i];
                koncerty[i] += koncerty[i-1];
        }

        cin >> n;
        int s,e;
        for(int i = 0; i< n; i++)
        {
                cin >> s >> e;

                cout << koncerty[e] - koncerty[s-1] << "\n";
        }

        return 0;
}    
