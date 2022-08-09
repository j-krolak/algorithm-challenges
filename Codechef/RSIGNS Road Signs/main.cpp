/*
 * Link: https://www.codechef.com/problems/RSIGNS?tab=statement
 */
#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
typedef long long ll;

ll qpow(ll a, ll b)
{
    if(b==0)
        return 1;
    ll res = qpow(a, b/2);
    res = (res*res)%MOD;
    
    if(b%2==1)
        return (res*a) % MOD;
    return res;
    
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	int t,k;
	ll res;
	cin >> t;
	
	while(t--)
	{
	    cin >> k;
	    
	    res = (10 * qpow(2,k-1))%MOD;
	    cout << res << "\n";
	}
	
	return 0;
}

