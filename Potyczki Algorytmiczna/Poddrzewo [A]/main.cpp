#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

vector<int> a;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
		sum += tmp;
	}
	
	sort(a.begin(), a.end());
	
 	sum = 0;
	
	for(int i = 0;i<n; i++)
	{
		sum += a[i];
		
		if( i > 0 && sum == (i)*2)
		{
			cout << "0\n";
			cout << i + 1 << "\n";
			int k = 1;
			for(int j = 0; j < i; j++)
			{
				k=max(k, j + 1);
				for(;k < n && a[k] > 1; k++)
				{
				}
				
				cout << j+1 << " " << k+1 << "\n";
				
			} 	
			a[k]--;
						
			return 0;
		}
	}
	
	for(int i = 0; i < n-1; i++)
	{
		if(a[i] == 1)
		{
			cout << "1\n2\n" << i+1 << " " << i+2 << "\n";
			return 0;
		}

	}
	
	/*sum = 0;
	for(int i = 0;i<n; i++)
	{
		sum += a[i];
		
		if( i > 0 && sum > (i)*2 && a[i] > sum - i*2)
		{
			cout << "1\n";
			cout << i + 1 << "\n";
			a[i] -= sum - i*2;
			int k = 1;
			for(int j = 0; j < i; j++)
			{
				k=max(k, j + 1);
				for(;k < n && a[k] > 1; k++)
				{
				}
				
				cout << j+1 << " " << k+1 << "\n";
				a[k]--;
				
			} 	
			return 0;
		}
		
		if( i > 0 && sum < (i)*2 && a[0]+i*2-sum <= i)
		{
			cout << "1\n";
			cout << i + 1 << "\n";
			a[0] += i*2-sum	;
			sort(a.begin(), a.begin() + i+1);
			int k = 1;
			for(int j = 0; j < i; j++)
			{
				k=max(k, j + 1);
				for(;k < n && a[k] > 1; k++)
				{
				}
				
				cout << j+1 << " " << k+1 << "\n";
				a[k]--;
				
			} 	
			return 0;
		}
	}*/
	
	cout << "2\n2\n1 2\n";
	


	return 0;
}



