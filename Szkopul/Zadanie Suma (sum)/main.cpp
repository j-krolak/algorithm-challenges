#include<bits/stdc++.h>

using namespace std;

int main()
{
	cout.tie(0);
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cout << "1";
	for(int i = 1; i < n; i++)
		cout << "0";
	cout << "\n";
	return 0;
}
