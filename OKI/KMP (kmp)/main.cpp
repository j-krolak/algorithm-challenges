#include<bits/stdc++.h>

using namespace std;

int n,m;
string pat, txt;

vector<int> prefsuf;

void c()
{
	int j = 0; 
	prefsuf[1] = 0;
	
	for(int i = 2; i <= n; i++)
	{
		while(j && pat[j+1] != pat[i]) j = prefsuf[j];
		if(pat[j+1] == pat[i])
			j++;
		prefsuf[i] = j;
	}
}

void s()
{
	int j = 0;
	
	for(int i =1; i <= m ; i++)
	{
		while(j && pat[j+1] != txt[i]) j = prefsuf[j];
		
		if(pat[j+1] == txt[i])
			j++;
			
		if(j == n)
		{
			cout << i-n+1 << "\n";
			j = prefsuf[j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> pat >> txt;
	prefsuf.resize(n+1);
	pat = " " + pat;
	txt = " " + txt;
	c();
	s();
	return 0;
}
