/*
 * Link: https://leetcode.com/problems/min-cost-to-connect-all-points/
 */
class Solution {
public:
	int r[1023];

	int Find(int val)
	{
		if(r[val] != val)
			r[val] = Find(r[val]);
		return r[val];
	}

	void Union(int a, int b)
	{
		r[Find(a)] = Find(b);
	}

	int minCostConnectPoints(vector<vector<int>>& points) 
	{
        vector<pair<int, pair<int,int>>> d;

		for(int i = 0; i < points.size(); i++)
		{
			for(int j = i + 1; j < points.size(); j++)
			{
				int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
				d.push_back({dist, {i,j}});
			}
		}

		sort(d.begin(), d.end());


		for(int i = 0; i < 1023; i++)
			r[i] = i;

		int ans = 0;

		for(int i = 0; i < d.size(); i++)
		{
			if(Find(d[i].second.first) != Find(d[i].second.second))
			{
				Union(d[i].second.first, d[i].second.second);
				ans += d[i].first;
			}
		}

		return ans;
	}

};

