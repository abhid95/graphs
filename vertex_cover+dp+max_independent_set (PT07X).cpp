/* vertex cover using largest independent set of tree
 as max_independent_set+vertex_cover=number of vertices */

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
int dp[2][100005];
vector<int> adj[100005];
queue<int> q;
int func(int u,int par,int opt)
{
    int si=0,se=0,i;
    if(dp[opt][u]!=-1)
        return dp[opt][u];
    for(i=0;i<adj[u].size();i++)
    {
        if(adj[u][i]!=par)
        {
            if(!opt)
                se+=max(func(adj[u][i],u,0),func(adj[u][i],u,1)+1);
            else
                si+=func(adj[u][i],u,0);
        }
    }
    return dp[opt][u]=max(se,si);
}

int main()
{
int i,j,l,n,m,t,T,f,p,ans,cnt,par,ele,u,v;
char x;
s(n);
memset(dp[0],-1,sizeof dp[0]);
memset(dp[1],-1,sizeof dp[1]);
FOR(n-1)
{
    scanf("%d%d",&u,&v);
    u--;
    v--;
    adj[u].pb(v);
    adj[v].pb(u);

}
ans=max(func(0,-1,0),func(0,-1,1)+1);
p(n-ans);

return 0;
}



