#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <utility>

using namespace std;

int N;
int a[101];

int main()
{
	int sum = 0;
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}
	sum = sum / N;
	for (int i = 0; i < N - 1; ++i)
	{
		if (a[i] != sum)
		{
			a[i + 1] += a[i] - sum;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}