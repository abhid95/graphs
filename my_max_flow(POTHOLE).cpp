#include <bits/stdc++.h>
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define FOR(n) for(i=0;i<n;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define reps(i,a,b) for(i=a;i<=b;i++)
#define swap(a,b) T=a,a=b,b=T
#define ll long long int
#define que queue<int>
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
using namespace std;
int graph[205][205];
int n;
int rGraph[205][205];
bool bfs(int s,int t,int parent[])
{
    bool visited[205];
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0;v<n;v++)
        {
            if(visited[v]==false && rGraph[u][v]>0)
            {
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return(visited[t]==true);
}
int fordFulkerson(int s,int t)
{
    int u,v;
    for(u=0;u<n;u++)
        for(v=0;v<n;v++)
            rGraph[u][v]=graph[u][v];
    int parent[n];
    int path_flow;
    if(bfs(s,t,parent))
    {
        path_flow=INT_MAX;
        for(v=t;v!=s;v=parent[v])
        {
            u=parent[v];
            path_flow=min(path_flow,rGraph[u][v]);
        }
        for(v=t;v!=s;v=parent[v])
        {
            u=parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[u][v]+=path_flow;
        }
    }
    return path_flow!=1?0:path_flow;
}
int main()
{
int i,j,k,l,m,t,T,f,p,ans,cnt,par,x;
s(t);
while(t--)
{
    int max_flow=0;
    s(n);
    FOR(n-1)
    {
        s(m);
        for(j=0;j<m;j++)
        {
            s(x);
            x--;
            graph[i][x]=(i==0 || x==n-1)?1:INT_MAX;
        }
    }
    while(1)
    {
        p=fordFulkerson(0,n-1);
        if(!p)
            break;
        max_flow+=p;
        cout<<p<<endl;
    }
    printf("%d\n",max_flow);
}

return 0;
}


