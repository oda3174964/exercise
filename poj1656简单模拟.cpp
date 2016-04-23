#include <iostream>
#include <string>

using namespace std;

int table[101][101];

int N;

int main()
{
	table[0][0] = 0;

	cin >> N;
	string str;
	int x, y, l;
	int m, n;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		cin >> x >> y >> l;
		if (str == "BLACK")
		{
			for (int m = x; m <= (x + l - 1); m++)
				for (int n = y; n <= (y + l - 1); n++)
					table[m][n] = 1;
		}
		else if (str == "WHITE")
		{
			for (int m = x; m <= (x + l - 1); m++)
				for (int n = y; n <= (y + l - 1); n++)
					table[m][n] = 0;
		}
		else
		{
			int cnt = 0;
			for (int m = x; m <= (x + l - 1); m++)
			{
				for (int n = y; n <= (y + l - 1); n++)
				{
					if (table[m][n] == 1)
						cnt++;
				}
			}
			cout << cnt << endl;
		}
	}
	return 0;
}