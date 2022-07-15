/*
 * URL: https://turnieje.solve.edu.pl/tasks/view/19
 */
#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

long long pass[MAXN];
long long pref[MAXN];


int binary_search(vector<int> &array, int value)
{
	int begin=0, end=array.size()-1, mid;

	while(begin < end)
	{
		mid = (begin+end)/2;
		if(array[mid] >= value)
			end = mid;
		else
			begin = mid + 1;
	}

	
	while(end >= 0&& array[end] > value)
		end--;
	
	end += 1;
	return end;
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> pass[i];
		pref[i] = pref[i-1] + pass[i];
	}

	map<long long, vector<int>> mp;

	for(int i = 0; i <= n; i++)
	{
		if(mp[pref[i]].size() == 0)
			mp[pref[i]] = vector<int>();
		mp[pref[i]].push_back(i);
	}

	long long ans = 0;

	for(int i = 2; i <= n; i++)
	{
		long long a = pref[i-1] - pass[i];
		int ind = binary_search(mp[a],i-2);
		ans += ind;
	}

	cout << ans << "\n";

	return 0;
}
