#include <bits/stdc++.h>

using namespace std;

vector<int> bierki;

int find(int num)
{
	int low,high,mid;
	low = 0;
	high = bierki.size()-1;

	while(low <= high)
	{
		mid = low + (high - low)/2;

		if(bierki[mid] == num)
			return mid;
		if(bierki[mid] < num)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return mid;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	int b;
	for(int i = 0; i < n;i++)
	{
		cin >> b;
		bierki.push_back(b);
	}

	sort(bierki.begin(), bierki.end());
	
	int ans = 0;
	int k;
	int r;
	while(bierki.size() > 2)
	{
		r = 0;
		b = bierki[0] + bierki[1];
		k = find(b);
		while(bierki[k] >= b && k > 0)
		{
			k--;
		}
		r = k + 1;
		ans = max(ans, r);

		bierki.erase(bierki.begin());
	}
	
	cout << ans << "\n";	
	return 0;
}

