#include<bits/stdc++.h>
 
using namespace std;
 
int chars_count[26] = { 0 };
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string txt;
	cin >> txt;
 
	// A-Z = (ASCI) 65 - 90
	for(char x : txt)
		chars_count[ int(x) - 65]++;
 
	int odds = 0;
	int odd_i = -1;
	for(int i = 0; i < 26; i++)
	{
		if(chars_count[i] % 2 == 1)
		{
			odds++;
			odd_i = i;
		}
	}
 
	if(odds > 1)
	{
		cout << "NO SOLUTION\n";
		return 0;
	}
 
	char c;
 
	for(int i = 0; i < 26; i++)
	{
		c = char(i + 65);
		for(int j = 0; j < chars_count[i]/2; j++)
			cout << c;
	}
	if(odd_i != -1)
	{
		cout << char(odd_i + 65);
		
 	}
	for(int i = 25; i >= 0; i--)
	{
		c = char(i + 65);
		for(int j = 0; j < chars_count[i]/2; j++)
			cout << c;
	}
	cout << "\n";
	return 0;
}
