#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e4 + 10;

int diamonds[MAXN];
int ogon[MAXN];

int main()
{
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, l;
	cin >> n >> l;
	
	for(int i = 0; i < n; i++)
	{
		cin >> diamonds[i];
	}

	
	sort(diamonds, diamonds + n);

	int p, k, s;

	p = 0;
	k = 0;
	s = 0;

	while(p < n && k < n)
	{
		if(s <= l)
			ogon[p] = max(ogon[p], k-p+1);

		if(s <= l)
		{
			k++;
		}
		else
		{
			p++;
		}

		s = diamonds[k] - diamonds[p];
	}

	for(int i = n-2; i >= 0; i--)
	{
		ogon[i] = max(ogon[i], ogon[i+1]);
	}

	
        p = 0;
        k = 0;
        s = 0;
	int ans = 0;
        while(p < n && k < n)
        {
		if(s <= l)
                {
                        ans = max(ans, k-p+1 + ogon[k+1]);
                }
        

                if(s <= l)
                {
                        k++;
                }
                else
                {
                        p++;
                }

                s = diamonds[k] - diamonds[p];
        }

	cout << ans << "\n";



	return 0;
}
