#include<bits/stdc++.h>

using namespace std;

constexpr long long P = 199;
constexpr long long MOD = 1e9 + 7;
constexpr int MAXN = 1e6 + 2;


long long pows[MAXN];
long long hash1[MAXN];


bool hashcmp(int l, int r, int m, long long patternHash);


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	//-----------------------------------------------------------------------

	pows[0] = 1;
	for(int i = 1; i < MAXN; i++)
	{
		pows[i] = (pows[i-1] * P)%MOD;
	}

	//-----------------------------------------------------------------------
	
	string n, m;
	cin >> n >> m;
	
	int ns = n.size();
	int ms = m.size();
	
	
	long long patternHash = 0;

	
	for(int i = 0; i < ms; i++)
	{
		patternHash = (patternHash + m[i] * pows[i])%MOD;
	}
		
	
	for(int i = 0; i < ns; i++)
	{
		hash1[i+1] = (hash1[i] + (long long)(n[i]) * pows[i])%MOD;
	}
	
	
	for(int i = ms - 1; i < ns; i++)
	{
		if(hashcmp(i-ms+1,i,ms,patternHash))
		{
			for(int j = 0; j < ms; j++)
			{
				if(n[i-j] <= 'Z') break;
				
				n[i-j] -= 32;
			}
		}	
	}
		
	cout << n << '\n';
	return 0;
}









bool hashcmp(int l, int r, int m, long long patternHash)
{
	long long cHash = 0;
	
	r++;
	l++;
	// 0 1 2 3 4 5
	// --<------->
	cHash = (hash1[r] - hash1[l-1] + MOD) % MOD;
	patternHash = (pows[l-1] * patternHash)%MOD;
	return cHash == patternHash;
	
}



