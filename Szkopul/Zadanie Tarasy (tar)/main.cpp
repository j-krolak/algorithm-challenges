#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e4 + 10;

int l,n;

int tarasy[MAXN];
int c[MAXN];

int main()
{
	cin >> n >> l;

	for(int i = 0; i < n; i++)
	{
		cin >> tarasy[i];
	}

	int ans = 0;

	int p,k;
	p = 0;
	k = 0;
	int s = 0;
	while(p < n)
	{
		ans = max(ans, s <= l ? k-p+1: 0);
		if(s <= l && k < n-1)
		{
			k++;
				
			if(tarasy[k] > tarasy[k-1])
			{
				s += tarasy[k] - tarasy[k-1];
			}
		}
		else
		{
			p++;
			if(tarasy[p] > tarasy[p-1])
			{
				s-= tarasy[p] - tarasy[p-1];
			}
		}

	}

	reverse(tarasy, tarasy + n);
	
	p = 0;
        k = 0;
        s = 0;
        while(p < n)
        {
                ans = max(ans, s <= l ? k-p+1: 0);
                if(s <= l && k < n-1)
                {
                        k++;

                        if(tarasy[k] > tarasy[k-1])
                        {
                                s += tarasy[k] - tarasy[k-1];
                        }
                }
                else
                {
                        p++;
                        if(tarasy[p] > tarasy[p-1])
                        {
                                s-= tarasy[p] - tarasy[p-1];
                        }
                }

        }

	cout << ans << endl;

	return 0;
}
