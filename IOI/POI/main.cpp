#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e3 + 10;

int score[MAXN];
int task[MAXN];
vector<int> cont[MAXN];

bool check(int a, int b)
{
	if(score[a] > score[b])
		return true;

	if(score[a] == score[b])
	{
		if(cont[a].size() > cont[b].size())
			return true;
		if(cont[a].size() == cont[b].size())
			return a < b;
		return false;
	}
		
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	int n, t, p, tmp;
	cin >> n >> t >> p;
	p--;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < t; j++)
		{
			cin >> tmp;
			if(tmp == 0)
				task[j]++;
			else
				cont[i].push_back(j);
		}
	}
	vector<int> cont_s;

	for(int i = 0; i < n; i++)
	{
		for(size_t j = 0; j < cont[i].size(); j++)
		{
			score[i] += task[cont[i][j]];
		}
		cont_s.push_back(i);
	}

	sort(cont_s.begin(), cont_s.end(), check);

	for(int i = 0; i < n; i++)
	{
		if(cont_s[i] == p)
		{
			cout << score[cont_s[i]] << " " << i+1 << "\n";
			return 0;
		}
	}

	return 0;
}
