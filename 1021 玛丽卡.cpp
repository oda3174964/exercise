/*
第一行有两个用空格隔开的数N和M，分别表示城市的数量以及城市间道路的数量。1≤N≤1000，1≤M≤N*(N-1)/2。
城市用数字1至N标识，麦克在城市1中，玛丽卡在城市N中。

接下来的M行中每行包含三个用空格隔开的数A，B和V。其中1≤A，B≤N，1≤V≤1000。
这些数字表示在A和城市B中间有一条双行道，并且在V分钟内是就能通过。

输出文件的第一行中写出用分钟表示的最长时间，在这段时间中，无论哪条路在堵车，
玛丽卡应该能够到达麦克处，如果少于这个时间的话，则必定存在一条路，该条路一旦堵车，玛丽卡就不能够赶到麦克处。
*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1100,maxm=(maxn-1)*maxn/2;
struct data{int to,next,w;}e[maxm];
int del[maxm],ans,head[maxn],edge[maxn],cnt,dis[maxn];
bool inq[maxn];
void ins(int u,int v,int w)
{
    e[cnt].next=head[u];
    head[u]=cnt;
    e[cnt].w=w;
    e[cnt].to=v;
    cnt++;
}
void spfa()
{
    memset(inq,0,sizeof(inq));
    queue<int> q;
    memset(dis,127/3,sizeof(dis));
    dis[1]=0;
    inq[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inq[u]=0;
        for(int i = head[u]; i != -1; i = e[i].next)
            if(!del[i] && dis[e[i].to] > dis[u]+e[i].w)
            {
                dis[e[i].to] = dis[u] + e[i].w;
                if(!inq[e[i].to])
                {
                    inq[e[i].to] = 1;
                    q.push(e[i].to);
                }
            }
    }
}
int main()
{
    int n,m;
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        ins(u, v, w);
        ins(v, u, w);
    }
    spfa();
    int t = n;
    cnt = 0;
    while(t != 1)
    {
        for(int i = head[t]; i != -1 ;i = e[i].next)
            if(dis[t] == dis[e[i].to]+e[i].w)
            {
                edge[++cnt] = i;
                t = e[i].to;
                break;
            }
    }
    for(int i=1;i<=cnt;i++)
    {
        del[edge[i]]=1;
        del[edge[i]^1]=1;
        spfa();
        ans = max(ans, dis[n]);
        del[edge[i]] = 0;
        del[edge[i]^1] = 0;
    }
    printf("%d",ans);
    return 0;
}