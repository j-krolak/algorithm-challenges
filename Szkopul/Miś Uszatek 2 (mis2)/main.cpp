/*
 * Link: https://szkopul.edu.pl/problemset/problem/5T1xklMhLwENJxW93pKkw1Dk/site/?key=statement
 */
#include<iostream>

using namespace std;

constexpr int MAXN=6e5+7;

typedef long long ll;

ll h[MAXN];

int partition(int low, int high)
{
	int i = low - 1;
	int j = high + 1;
	ll pivot = h[(low+high)/2];

	while(true)
	{
		while(h[++i] <  pivot);
		while(h[--j] > pivot);
		if(i >= j)
			break;
		swap(h[i], h[j]);
	}
	return j;
}

void sort(int low, int high)
{
	if(low >= high)
		return;
	int pivot = partition(low, high);
	sort(low, pivot);
	sort(pivot+1, high);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n ;i++)
		cin >> h[i];

	sort(0, n-1);

	for(int i = 0; i < n; i++)
	{
		cout << h[i] << " ";
	}
	cout << "\n";
	return 0;
}
