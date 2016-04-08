#include <iostream>
#include <cstdio>
using namespace std;

int f[100][100];
int getf(int x, int y)
{
    if(f[x][y] != -1)
        return f[x][y];
    int result;
    if(x == 0 || y == 0)
        result = 1;
    else
        result = getf(x-1, y) + getf(x, y-1);
    f[x][y] = result;
    return result;
}

int main(int argc, char* argv[])
{
    int i, j, n;
    memset(f, -1, sizeof(f));
    while(cin >> n)
    {
        if(n == 0)
            break;
        cout << getf(n, n) << endl;
    }
    return 0;
}