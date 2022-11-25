#include <string>
#include <iostream>

using namespace std;

typedef long long ll;
constexpr ll P = 199;
constexpr ll MOD = 1e9 + 7;
constexpr int MAXN  = 1e6 + 10;

ll pows[MAXN];
ll hasht[MAXN];

bool cmphash(int l, int r, int m, ll pattern);

int main()
{

	//--------------------------------------
	
	pows[0] = 1;
	
	for(int i = 1; i < MAXN; i++)
	{
		pows[i] = (pows[i-1] * P)%MOD;
	}

	//--------------------------------------
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	string n, m;
	cin >> n >> m;
	
	
	ll pattern = 0;
	
	for(int i = 0; i < m.size(); i++)
	{
		pattern = (pattern + pows[i] * m[i])%MOD;
	}
	
	
	for(int i = 1; i <= n.size(); i++)
	{
		hasht[i] = hasht[i-1] + n[i-1]*pows[i-1];
	}
	
	
	int ans = 0;
	
	
	for(int i = m.size(); i <= n.size(); i++)
	{
	
		if(cmphash(i-m.size()+1, i, m.size(), pattern))
		{
			ans++;
		}
	
	}
	
	cout << ans << '\n';
		
	return 0;
}


bool cmphash(int l, int r, int m, ll pattern)
{
	ll tmphash = (hasht[r] - hasht[l-1] + MOD) % MOD;
	
	pattern = (pattern * pows[l-1])%MOD;
	return pattern == tmphash;
}





















