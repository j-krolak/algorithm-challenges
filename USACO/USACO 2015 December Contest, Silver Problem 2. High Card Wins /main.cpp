/* 
 * Score: 15/15
 * Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=571
 * Author: Jakub Królak
 */
#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdoutgi);


	int n;
	cin >> n;

	bool hasElsie[2*n+1] = {false};

	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		hasElsie[tmp] = true;
	}

	vector<int> elsie, bessie;

	for(int i = 1; i <= 2*n; i++)
	{
		if(hasElsie[i])
		{
			elsie.push_back(i);
		}
		else
		{
			bessie.push_back(i);
		}

	}

	sort(elsie.begin(), elsie.end());
	sort(bessie.begin(), bessie.end());

	int points = 0;

	int elsieI = 0;
	int bessieI = 0;

	while(elsieI <= elsie.size() && bessieI <= bessie.size())
	{
		if(bessie[bessieI] > elsie[elsieI])
		{
			points++;
			elsieI++;
			bessieI++;
		}
		else
		{
			bessieI++;
		}
	}

	cout << points << "\n";

	return 0;
}
