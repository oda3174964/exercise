#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct node
{
	int id;
	int time;
	int init;
	
	friend bool operator<(node a, node b)
	{
		if (a.time == b.time)
			return a.id > b.id;
		else
			return a.time > b.time;
	}
};

int main()
{
	string str;
	cin >> str;
	priority_queue<node> q;
	while (str != "#")
	{
		node t;
		cin >> t.id >> t.init;
		t.time = t.init;
		q.push(t);
		cin >> str;
	}
	int num;
	cin >> num;
	while (num--)
	{
		node t = q.top();
		cout << t.id << endl;
		t.time += t.init;
		q.pop();
		q.push(t);
	}

	system("pause");
	return 0;
}