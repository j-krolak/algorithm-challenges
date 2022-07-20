#include<bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
	while(b != 0)
	{
		int tmp = b;
		b = a%b;
		a = tmp;
	}

	return a;
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
		int n,d;
		cin >> n >> d;

		cout << n/GCD(n,d) << "\n";
	}

	return 0;
}
