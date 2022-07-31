/*
 * Link: http://www.usaco.org/index.php?cpid=671&page=viewproblem2
 */
#include<bits/stdc++.h>

using namespace std;

pair<int, int> laser;
pair<int, int> barn;

map<pair<int, int>, int> fence;
	
map<int, vector<pair<int, int>>> xAxis;
map<int, vector<pair<int, int>>> yAxis;

int main()
{
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n >> laser.first >> laser.second >> barn.first >> barn.second;
	
	xAxis[barn.first].push_back(barn);
	yAxis[barn.second].push_back(barn);
	pair<int, int> tmp;
	for(int i = 0; i < n; i++)
	{

		cin >> tmp.first >> tmp.second;
		xAxis[tmp.first].push_back(tmp);
		yAxis[tmp.second].push_back(tmp);
	}
	
	
	vector<pair<int, int>> onY;
	vector<pair<int, int>> onX;
	queue<pair<int, int>> Q;
       	Q.push(laser);
	fence[laser] = 0;
	while(!Q.empty())
	{
		tmp = Q.front();
		Q.pop();
		
		if(xAxis.find(tmp.first) != xAxis.end())
		{
			onX = xAxis[tmp.first];
			xAxis.erase(tmp.first);
		}
		else
		{
			onX.resize(0);
		}

		if(yAxis.find(tmp.second) != yAxis.end())
		{
			onY = yAxis[tmp.second];
			yAxis.erase(tmp.second);
		}
		else
		{
			onY.resize(0);
		}
		int k = fence[tmp] + 1;

		for(int i = 0; i < onX.size(); i++)
		{
			if(fence.find(onX[i]) != fence.end())
				continue;
			Q.push(onX[i]);
			fence[onX[i]] = k;
		}

		for(int i = 0; i < onY.size(); i++)
		{
			if(fence.find(onY[i]) != fence.end())
				continue;
			Q.push(onY[i]);
			fence[onY[i]] = k;
		}

	if(fence.find(barn) != fence.end())
	{
		int ans = fence[barn] - 1;
		cout << ans << "\n";
		return 0;
	}


		
	}
	cout << "-1\n";
	return 0;

}
