#include <bits/stdc++.h>

using namespace std;

void reverse_str(string &str)
{
	int length = str.length();

	for(int i = 0; i < length/2; i++)
	{
		swap(str[i], str[length-1-i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while(n-- > 0)
	{
		int c;
		cin >> c;
		int b[c];
		for(int i = 0; i < c; i++)
		{
			cin >> b[i];
		}


		int d=0;
		string result;
		for(int  i = c-1; i >= 0; i--)
		{
			if(b[i] > d)
			{
				d = b[i];
			}

			if(d > 0)
			{
				result += "1 ";
				d--;
			}
			else
			{
				result += "0 ";
			}
		}

		reverse_str(result);

		cout << result << endl;



	}

	return 0;
}
