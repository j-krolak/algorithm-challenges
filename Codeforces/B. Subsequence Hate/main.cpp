#include<bits/stdc++.h>

using namespace std;

void solve()
{
	string binS;
	cin >> binS;
	int count0 = 0,count1 = 0,all0=0,all1=0;
	
	for(char i : binS)
	{
		if(i == '0')
			all0++;
		else
			all1++;
	}

	int ans = binS.size();

	for(char i : binS)
	{
		if(i == '0')
			count0++;
		else
			count1++;

		ans = min(ans, count1+ all0-count0);
		ans = min(ans, count0 + all1 - count1);
	}
	
	cout << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int qn;
	cin >> qn;

	for(int i = 0; i < qn; i++)
	{
		solve();
	}
	return 0;
}
