#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e4 + 10;

int guests[MAXN];
bool visited[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> guests[i];
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(visited[i])
			continue;
			
		ans++;
		
		int tmp = i;
		while(!visited[tmp])
		{
			visited[tmp] = true;
			tmp = guests[tmp];
		}
	}
	cout << ans << "\n";
	return 0;
}
