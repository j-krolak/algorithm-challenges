#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 60;

int arr[MAXN];

void sol();

int main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	while(n--)
		sol();
	return 0;
}


void sol()
{
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	string s;
	cin >> s;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(arr[i] == arr[j] && s[i] != s[j])
			{
				cout << "NO\n";
				return;
			}

		}
	}

	cout << "YES\n";

}











