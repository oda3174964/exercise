#include <iostream>
#include <string>
using namespace std;

//用树状数组来做
int table[101][101];
int flag[101][101];

int lowBit(int i)
{
	return i & (-i);
}

void Update(int x, int y, int color)
{
	if (color == flag[x][y])
		return;
	flag[x][y] = color;
	for (int i = x; i <= 100; i += lowBit(i))
	{
		for (int j = y; j <= 100; j += lowBit(j))
		{
			table[i][j] += color;
		}
	}
}

int Query(int x, int y)
{
	int sum = 0;
	for (int i = x; i > 0; i -= lowBit(i))
		for (int j = y; j > 0; j -= lowBit(j))
			sum += table[i][j];

	return sum;
}

int main()
{
	int N;
	table[0][0] = 0;
	memset(flag, -1, sizeof(flag));
	string str;
	int x, y, l;
	cin >> N;
	for (int k = 0; k < N; k++)
	{
		cin >> str;
		cin >> x >> y >> l;
		if (str == "BLACK")
		{
			for (int i = x; i <= x + l - 1; i++)
				for (int j = y; j <= y + l - 1; j++)
					Update(i, j, 1);
		}
		else if (str == "WHITE")
		{
			for (int i = x; i <= x + l - 1; i++)
				for (int j = y; j <= y + l - 1; j++)
					Update(i, j, -1);
		}
		else
		{
			cout << Query(x + l - 1, y + l - 1) - Query(x + l - 1, y - 1) - Query(x - 1, y + l - 1) + Query(x - 1, y - 1) << endl;
		}
	}
	return 0;
}