//
//  main.cpp
//  exercise
//
//  Created by Kakarotto on 16/1/28.
//  Copyright © 2016年 Kakarotto. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int k = 26;
const int MAXN = 500100;
struct Node
{
    Node* ch[k], *fail;
    int match;
    void clear()
    {
        memset(this, 0, sizeof(Node));
    }
};
Node* que[MAXN];
struct ACAutomaton
{
    Node nodes[MAXN], *root, *superRoot, *cur;
    Node* newNode()//从内存中初始化一个结点
    {
        cur->clear();
        return cur++;
    }
    void clear()
    {
        cur = nodes;
        superRoot = new Node();
        root = new Node();
        root->fail = superRoot;
        for(int i = 0; i < k; ++i)
            superRoot->ch[i] = root;
        superRoot->match = -1;
    }
    void insert(char* s)//向字典树种添加一个字符串
    {
        Node* t = root;
        for(; *s; ++s)
        {
            int x = *s - 'a';
            if(t->ch[x] == NULL)
                t->ch[x] = new Node();
            t = t->ch[x];
        }
        t->match++;
    }
    void build() //构建自动树
    {
        int p = 0, q = 0;
        que[q++] = root;
        while(p != q)
        {
            Node* t = que[p++];
            for(int i = 0; i < k; ++i)
            {
                if(t->ch[i])
                {
                    t->ch[i]->fail = t->fail->ch[i];
                    que[q++] = t->ch[i];
                }
                else
                    t->ch[i] = t->fail->ch[i];
            }
        }
    }
    int run(char* s)
    {
        int ans = 0;
        Node* t = root;
        for(; *s; s++)
        {
            int x = *s - 'a';
            t = t->ch[x];
            for(Node* u = t; u->match != -1; u = u->fail)
            {
                ans += u->match;
                u->match = -1;
            }
        }
        return ans;
    }
};

char s[1000100];
ACAutomaton c;
int n;

int main()
{
    //std::cout << "Hello, World!\n";
    int cas, i;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        c.clear();
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", s);
            c.insert(s);
        }
        c.build();
        scanf("%s", s);
        printf("%d\n", c.run(s));
    }
    return 0;
}
