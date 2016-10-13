#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int dp[1005];

struct Node
{
	int time;
	int value;
}a[105];

int main()
{
	int i, j, t, m;
	scanf("%d%d", &t, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &a[i].time, &a[i].value);
	}
	for (i = 1; i <= m; ++i)
	{
		for (j = t; j >= a[i].time; j--)
		{
			dp[j] = max(dp[j], dp[j - a[i].time] + a[i].value);
		}
	}
	printf("%d\n", dp[t]);
	return 0;
}