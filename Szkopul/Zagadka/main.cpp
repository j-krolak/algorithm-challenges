#include <bits/stdc++.h>

using namespace std;
int main()
{
	int a,b;

	cin >> a  >> b;

	int c = a*b;
	int d = b - 1;
	if(c % d != 0)
		cout << "NIE" << endl;
	else
		cout << c/d << endl;
	return 0;
}
