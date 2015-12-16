#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int x, y, h;
	friend bool operator<(node a, node b)
	{
		return a.h > b.h;
	}
};

int table[310][310];
bool vis[310][310];

int ans = 0;
int way[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };

int main()
{
	ans = 0;
	priority_queue<node> q;
	node a, b;
	int line, row;
	cin >> line >> row;

	memset(vis, false, sizeof(vis));

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= line; j++)
			cin >> table[i][j];
	}

	for (int i = 1; i <= line; i++)
	{
		a.x = 1, a.y = i;
		a.h = table[1][i];
		vis[a.x][a.y] = true;
		q.push(a);

		a.x = row, a.y = i;
		a.h = table[row][i];
		vis[a.x][a.y] = true;
		q.push(a);
	}

	for (int i = 1; i <= row; i++)
	{
		a.x = i, a.y = 1;
		a.h = table[i][1];
		vis[a.x][a.y] = true;
		q.push(a);

		a.x = i, a.y = line;
		a.h = table[i][line];
		vis[a.x][a.y] = true;
		q.push(a);
	}

	while (!q.empty())
	{
		a = q.top();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			b.x = a.x + way[i][0];
			b.y = a.y + way[i][1];
			if (b.x <= 0 || b.x > row || b.y <= 0 || b.y > line)
				continue;
			if (vis[b.x][b.y])
				continue;

			vis[b.x][b.y] = true;

			if (table[b.x][b.y] > a.h)
			{
				int t = table[b.x][b.y];
				b.h = t;
				q.push(b);
				continue;
			}
			b.h = a.h;
			ans += a.h - table[b.x][b.y];
			q.push(b);
		}
	}

	cout << ans << endl;

	system("pause");
	return 0;
}