/*
 * Link: https://atcoder.jp/contests/dp/tasks/dp_e
 */
#include <bits/stdc++.h>

using namespace std;

constexpr int MAXA = 1e5 + 10;
constexpr int MAXN = 110;

int dp[MAXN][MAXA];
int v[MAXN];
int w[MAXN];

int fun(int ind, int val)
{
	if(val == 0)
	{	return 0;}
    if(ind == 0)
    {
	if(val != v[ind])
		return 1e9 + 1;
	return w[ind];
    }
    
    if(dp[ind][val] != -1)
        return dp[ind][val];
    
    int l = fun(ind - 1, val);
    if( val - v[ind] >= 0)
    {
        l = min(l, fun(ind-1, val - v[ind]) + w[ind]);
    }
    
    return dp[ind][val] = l;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    memset(dp, -1, sizeof(dp));
    
    int n, W;
    
    cin >> n >> W;
    
    for(int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    
    
    for(int i = MAXA; i >= 0; i--)
    {
	    if(fun(n-1, i) <= W)
        {
            cout << i << "\n";
            break;
        }
    }
    
    return 0;
}

