#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	map<char, int> mp[n];
	vector<string> words(n);
	bool visited[n] = {false};

	string tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		words[i] = tmp;
	}
	
	sort(words.begin(), words.end());

	for(int i = 0; i < n; i++)
	{
		tmp = words[i];
		for(int j = 0; j < tmp.size(); j++)
		{
			if(mp[i].find(tmp[j]) == mp[i].end())
				mp[i][tmp[j]]=0;
			mp[i][tmp[j]]++;
		}

	}

	for(int i = 0; i < n; i++)
	{
		if(visited[i])
			continue;
		map<string, bool> was;
		for(int j = 0; j < n; j++)
		{
			if(visited[j])
				continue;
			
			if(mp[i]==mp[j])
			{
				visited[j] = true;
				if( was.find(words[j]) == was.end())
					cout << words[j] << " ";
				was[words[j]] = true;
			}
		}
		cout << "\n";
	}

	return 0;
}
