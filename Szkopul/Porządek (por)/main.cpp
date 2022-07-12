#include <bits/stdc++.h>

using namespace std;


const int MAXN = 1e6 + 10;

long long rA[MAXN];

long long rPref[MAXN];
long long nPref[MAXN];
long long pairs[MAXN];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	
	string  buff;
	cin >> buff;

	long long r = 0;
	long long maxCom = 0;

	for(int i = 0; i < n; i++)
	{
		
		if(buff[i] == 'R')
		{
			r++;
		}
		else
		{
			maxCom += r;
		}

	}

	r = 0;
	for(int i = n; i >0; i--)
	{
		if(buff[i-1] == 'N')
		{
			r++;
		}
		else
		{
			rA[i] = r;
		}
	}

	r = 0;
	for(int i = 1; i <= n; i++)
	{

		if(buff[i-1] == 'R')
		{
			r += rA[i];
		}
		rA[i] = r;
	}


	for(int i = 1; i <= n; i++)
	{
		rPref[i] = rPref[i-1];

		if(buff[i-1] == 'R')
			rPref[i]++;
	}


	for(int i = n; i > 0; i--)
	{
		nPref[i] = nPref[i+1];
		nPref[i] += (buff[i-1] == 'N') ? 1 : 0;
	}

	r = 0;

	for(int i = n; i > 0; i--)
	{
		if(buff[i-1] == 'R')
		{
			pairs[i] = r;
		}
		else
		{
			r++;
		}
	}

	r = 0;
	for(int i = n; i > 0; i--)
	{
		if(buff[i -1] == 'R')
		{
			pairs[i] += r;
			r = pairs[i];
		}
		else
		{
			pairs[i] = r;
		}
	}




	int qn;
	cin >> qn;

	for(int i = 0; i < qn; i++)
	{
		int s,e;
		cin >> s >> e;
		long long result = maxCom - rA[s-1] - (rPref[e] - rPref[s-1]) * (nPref[e+1]) - pairs[e+1];
		
		cout << result << endl;
	}


	return 0;
}
