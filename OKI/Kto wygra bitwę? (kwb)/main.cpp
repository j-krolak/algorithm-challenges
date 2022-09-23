#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int l, w=0, tmp;
	
	for(int i = 0; i < n*m; i++)
	{
		cin >> tmp;
		if(tmp == 0)
			continue;
		if(w == 0)
		{
			l = tmp;
		}
		
		if(tmp == l)
			w++;
		else
			w--;
	} 
	
	cout << l << "\n";
	return 0;
}
