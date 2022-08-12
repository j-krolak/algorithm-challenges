/*
 * Link: https://codeforces.com/contest/1150/problem/B
 */
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	bool board[n][n];

	for(int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;

		for(int j = 0; j < n; j++)
		{
			if(tmp[j] == '#')
				board[i][j] = false;
			else
				board[i][j] = true;
		}
	}

	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(board[i][j])
			{
				if(i > n-3 || j < 1 || j > n-2)
				{
					cout << "NO\n";
					return 0;
				}


				if(!( board[i+1][j] && board[i+1][j+1] && board[i+1][j-1] && board[i+2][j]))
				{
					cout << "NO\n";
					return 0;
				}
				
				board[i][j] = false;
				board[i+1][j] = false;
				board[i+1][j+1] = false;
				board[i+1][j-1] = false;
				board[i+2][j] = false;
			}
		}
	}

	cout << "YES\n";

	return 0;
}
