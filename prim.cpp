#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
vector<PII> adj[100002];
bool vis[100002];
long minCost=0;
void prim()
{
    memset(vis,false,sizeof(vis));
    priority_queue<PII,vector<PII>,greater<PII> > Q;
    Q.push(make_pair(0,1));
    while(!Q.empty())
    {
        PII f=Q.top();
        Q.pop();
        int n=f.second;
        if(vis[n])continue;
        minCost+=f.first;
        vis[n]=true;
        for(int i=0;i<adj[n].size();i++)
        {
            if(!vis[adj[n][i].first])
            {
                Q.push(make_pair(adj[n][i].second,adj[n][i].first));
            }
        }
    }
}
int main()
{
    int n,m,x,y,w;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(y,w));
        adj[y].push_back(make_pair(x,w));
    }
    prim();
    cout<<minCost;
}
