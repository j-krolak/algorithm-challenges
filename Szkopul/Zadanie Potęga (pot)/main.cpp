#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cycle[] = {6,2,4,8};
 
	uint64_t n;
	cin >> n;

	cout << n << endl;
	int i = n % 4;
	if(n == 0)
		cout << "1" << endl;
	else
		cout << cycle[i] << endl;
	return 0;
}
