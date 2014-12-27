// satisfied for disconnected graph also
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
bool graph[2005][2005];
int colorArr[2005],n,vis[2005];
bool isBipartite(int src)
{
    int f=1;
    for(int i=0;i<n;i++)
        colorArr[i]=-1;
    colorArr[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        vis[u]=1;
        q.pop();
        for(int v=0;v<n;v++)
        {
            if(graph[u][v] && colorArr[v]==-1)
            {
                colorArr[v]=1-colorArr[u];
                q.push(v);
            }
            else if(graph[u][v] && colorArr[v]==colorArr[u])
                f=0;
        }
    }
    return f;
}

int main()
{
int i,j,l,t,T,f,p,ans,cnt,par,ele,k=0,m,u,v;
char x;
s(t);
while(t--)
{
    k++;
    s(n);
    s(m);
    FOR(n)
        memset(graph[i],0,sizeof graph[i]);
    f=1;
    memset(vis,0,sizeof vis);
    FOR(m){
        s(u);
        s(v);
        u--;
        v--;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    for(i=0;i<n;i++)
        {
            if(!vis[i])
                f=isBipartite(i);
            if(!f)
                break;
        }
    printf("Scenario #%d:\n",k);
    if(!f)
        printf("Suspicious bugs found!\n\n");
    else
        printf("No suspicious bugs found!\n\n");

}


return 0;
}



