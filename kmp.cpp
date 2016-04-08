#include <iostream>
#include <cstring>
using namespace std;

void GetNext(char* t, int next[])
{
    int i = 1;
    next[1] = 0;
    int j = 0;
    while(i < 7)
    {
        if(j == 0 || t[i] == t[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
    for(int k = 0; k < 7; ++k)
        cout << next[k];
    cout << endl;
}

int main()
{
    int next[50];
    char s[20] = {'0', 'a', 'b', 'a', 'a', 'b', 'c'};
    memset(next, 0, sizeof(int)*50);
    GetNext(s, next);
    return 0;
}