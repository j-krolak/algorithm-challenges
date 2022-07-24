/*
 * Link: https://www.codechef.com/problems/COPAR
 */
#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int prime_f[MAXN];
int left_min[MAXN];
int right_max[MAXN];


void soe()
{
    
    for(int i = 2; i * i < MAXN; i++)
    {
        if(prime_f[i] == 0)
        {
            
            for(int j = 2*i; j < MAXN; j += i)
            {
                prime_f[j] = i;
            }
        }
    }

    for(int i = 0; i < MAXN; i++)
    {
        if(prime_f[i] == 0)
        {
            prime_f[i] = i;
        }
    }

}


void solve()
{
    int n;
    cin >> n;
    int num;

    for(int i = 1; i <= n; i++)
    {
        cin >> num;

        while(num > 1)
        {
            left_min[prime_f[num]] = min(left_min[prime_f[num]], i);
            right_max[prime_f[num]] = max(right_max[prime_f[num]], i);

            num = num/prime_f[num];
        }
    }

    int pref[n+1] = {0};
    for(int i = 2; i < MAXN; i++)
    {
        if(left_min[i] < MAXN)
        {
            pref[left_min[i]] += 1;
        }

        if(right_max[i] > 0)
        {
            pref[right_max[i]] -= 1;
        }

        left_min[i] = MAXN;
        right_max[i] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        pref[i] += pref[i-1];
    }

    for(int i = 1; i <= n; i++)
    {
        if(pref[i] == 0)
        {
            cout << i << "\n";
            return;
        }
    }

    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    soe();
    for(int i = 0; i < MAXN; i++)
    {
        left_min[i] = MAXN;
    }
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}