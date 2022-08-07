/*
 * Link: https://www.codechef.com/problems/MOVES?tab=statement
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const  ll M = 1000000007;
const int MAXN = 5e3 + 10;
ll silnia[MAXN]={ 1 };
ll o_silnia[MAXN]={ 1 };

ll qpow(ll a, ll b)
{
   ll res = 1;
   
   while(b > 0)
   {
       if(b % 2 == 1)
        res = (res * a) % M;
        
        a = (a*a)%M;
        b/=2;
   }
    return res;
}


ll mod_inverse(ll a)
{
    return qpow(a, M-2)%M;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i < 5000; i++)
    {
        silnia[i] = (silnia[i-1]*i)%M;
    }
    
    for(int i = 1; i < MAXN; i++)
        o_silnia[i] = mod_inverse(silnia[i]);
    int n, k;    
    while(cin >> n >> k && n != 0)
    {
        int ch = k/2;
        int cf =(k-1)/2;
        ll c = (silnia[n-2] * ((o_silnia[ch]%M*o_silnia[n-2-ch]) % M )) % M;
        ll c2 = (silnia[n-2] * ((o_silnia[cf]*o_silnia[n-2-cf]) % M) ) % M;
        ll res = (c*c2*2)%M;
        cout << res << "\n";
    }
    
	return 0;
}
