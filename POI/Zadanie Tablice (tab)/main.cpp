/*
 * Link: https://szkopul.edu.pl/problemset/problem/_i0PmDyArk7mCW0eUJJzEVOA/site/?key=statement
 */
#include<bits/stdc++.h>

using namespace std;



vector<vector<int>> load_arr(int n, int m)
{
	int tmp;
	vector<vector<int>> arr;

	for(int i = 0; i < n; i++)
	{
		arr.push_back({});
		for(int j =0; j < m; j++)
		{
			cin >> tmp;	
			arr[i].push_back(tmp);
		}
	}
	return arr;
}

void solve()
{
	int n,m, tmp;
	cin >> n >> m;

	vector<vector<int>> arr1 = load_arr(n, m);
	vector<vector<int>> arr2 = load_arr(n, m);

	vector<vector<int>> arr3;
	vector<vector<int>> arr4;

	for(int i = 0; i < m; i++)
	{
		arr3.push_back({});
		for(int j = 0; j < n;j++)
		{
			arr3[i].push_back(arr1[j][i]);
		}
	}


	for(int i = 0; i < m; i++)
	{
		arr4.push_back({});
		for(int j = 0; j < n ;j++)
		{
			arr4[i].push_back(arr2[j][i]);
		}
	}

	
	for(vector<int> &v : arr3)
	{
		sort(v.begin(), v.end());
	}
	sort(arr3.begin(), arr3.end());


	for(vector<int> &v : arr4)
	{
		sort(v.begin(), v.end());
	}
	sort(arr4.begin(), arr4.end());
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(arr3[i][j] != arr4[i][j])
			{
				cout << "NIE\n";
				return;
			}
		}
	}



	for(vector<int> &v : arr1)
	{
		sort(v.begin(), v.end());
	}
	sort(arr1.begin(), arr1.end());


	for(vector<int> &v : arr2)
	{
		sort(v.begin(), v.end());
	}
	sort(arr2.begin(), arr2.end());
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(arr1[i][j] != arr2[i][j])
			{
				cout << "NIE\n";
				return;
			}
		}
	}



	
	cout << "TAK\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
