#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int w,n;
	cin >> w >> n;
	vector<int> weights;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		weights.push_back(a);
	}
	
	sort(weights.begin(), weights.end());
	
	int j = 0;
	int ans = 0;
		
	for(int i = n-1; i >= 0; i--)
	{
		if(j>i)
			break;
		
		ans++;
		if(j==i)
			break;
		if(weights[i] + weights[j] <= w)
			j++;
	}
	
	cout << ans << "\n";
		
	return 0;
}
