#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 6e4+10;
constexpr double EPS = 1e-7;

int vel[MAXN];
int pos[MAXN];

bool possible(int n, double t)
{
	double L = 0;
	double R = 1e9;
	
	for(int i = 0; i < n; i++)
	{
		double ds = (double) vel[i] * t;
		double sL = pos[i] - ds;
		double sR = pos[i] + ds;

		L = max(L, sL);
		R = min(sR, R);

		if(L > R)
			return false;
	}

	return true;
}

double binary_search(int n)
{
	double begin = 0, end = (double) 1e9,mid;
	
	while(end - begin > EPS)
	{
		mid = (begin+end)/2;
		if(possible(n, mid))
			end = mid;
		else
			begin = mid;
	}

	return end;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> pos[i];
	}
	
	for(int i = 0; i < n; i++)
	{
		cin >> vel[i];
	}

	cout << fixed << setprecision(7);
	cout << binary_search(n) << "\n";

	return 0;
}
