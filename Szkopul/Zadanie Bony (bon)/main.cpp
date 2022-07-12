#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

bool bon[MAXN];
bool bought[MAXN];
int wiel[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int buff;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> buff;
		bon[buff] = true;		
	}

	vector<long long> klienci;
	long long klient = 0;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> buff;
		int licz = 0;
		for(int j = wiel[buff] + buff; j < MAXN; j += buff)
		{
			if(bought[j]) continue;
			if(licz == buff) break;
			klient++;
			bought[j] = 1;
			if(bon[j])
				klienci.push_back(klient);
			licz++;
			wiel[buff] = j;
		}

		klient += buff - licz;
	}

	cout << klienci.size() << "\n";
	for(auto a : klienci)
		cout << a << "\n";
	return 0;
}
