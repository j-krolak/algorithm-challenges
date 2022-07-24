#include<bits/stdc++.h>

using namespace std;


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    map<int, set<int> > mp;

    int w1, w2;
    for(int i = 0; i < m; i++)
    {
        cin >> w1 >> w2;

        mp[w1].insert(w2);
        mp[w2].insert(w1);

    }

    for(int i = 1; i <= n; i++)
    {
        if(mp.find(i) == mp.end())
        {
            cout << "Wiewior sam!";
        }
        else
        {
            set<int>::iterator it;
            set<int> s = mp[i];

            for(it = s.begin(); it != s.end(); it++)
            {
                cout << *it << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}
