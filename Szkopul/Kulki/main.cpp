#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

set<int> gora_c, gora_b, dol_c, dol_b;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout.tie(0);

	int n;
	string gs, ds;
	cin >> n >> gs >> ds;

	for(int i = 0; i < n; i++)
	{
		if(gs[i] == 'C')
			gora_c.insert(i);
		else
			gora_b.insert(i);

		if(ds[i] == 'C')
			dol_c.insert(i);
		else
			dol_b.insert(i);
	}

	long long wynik = min(gora_c.size(), gora_b.size());
	
	vector<int> a(wynik);
	vector<int> b(wynik);

	if(gora_c.size() > gora_b.size())
	{
		copy(gora_b.begin(), gora_b.end(), a.begin());
		copy(dol_c.begin(), dol_c.end(), b.begin());
	}
	else
	{
		copy(gora_c.begin(), gora_c.end(), a.begin());
		copy(dol_b.begin(), dol_b.end(), b.begin());
	}

	for(int i = 0; i < a.size(); i++)
	{
		wynik += abs(a[i] - b[i]);
	}

	cout << wynik << "\n";
	


	return 0;
}
