#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

vector<int> seq[MAXN];

int n;

int bs(vector<int> &v, int val)
{
	if(v.size() == 0)
		return -1;
	int lo = 0, hi = v.size()-1, mid;
	
	while(lo < hi)
	{
		mid = (lo+hi)/2;
		if(v[mid] < val)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid;
		}
	}
	
	
	if(v[lo] < val)
		return -1;
		
	return v[lo];
}

void solution()
{
	int m;
	cin >> m;
	vector<int> seq2;
	
		
	for(int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		seq2.push_back(tmp);
	}
	
	int j = 0;
	
	
	for(int i = 0; i < m; i++)
	{
		if(j >= n)
		{
			cout << "NIE\n";
			return;
		}
		j = bs(seq[seq2[i]], j);
		
		if(j == -1)
		{
			cout << "NIE\n";
			return;
		}
		
		j++;
	}
		
	cout << "TAK\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int m;
	
	cin >> m;
	n = m;
	for(int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		seq[tmp].push_back(i);
	}
	
	int n;
	cin >> n;
	while(n--)
	{
		solution();
	}
	
	return 0;
}
