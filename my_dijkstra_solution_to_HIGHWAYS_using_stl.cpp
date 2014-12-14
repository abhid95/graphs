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
#define pp pair<int,int>
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
using namespace std;
vector<pp> a[100005];
class Prioritize
{
public:
    int operator() ( const pair<int,int>&p1,const pair<int,int>&p2)
    {
        return p1.second>p2.second;
    }
};
int main()
{
int i,j,k,l,n,m,t,T,f,p,ans,cnt,par,d[100005],src,dest,dist,u,v;
char x;
priority_queue<pp,vector<pp >,Prioritize > q;
s(t);
while(t--)
{
    scanf("%d%d%d%d",&n,&m,&src,&dest);
    src--;
    dest--;
    FOR(m)
    {
        scanf("%d%d%d",&u,&v,&dist);
        u--;
        v--;
        a[u].pb(pp(v,dist));
        a[v].pb(pp(u,dist));
    }
    FOR(n)
        d[i]=999999;
    d[src]=0;
    q.push(pp(src,d[src]));
    while(!q.empty())
    {
        u=q.top().first;
        q.pop();
        for(i=0;i<a[u].size();i++)
        {
            v=a[u][i].first;
            dist=a[u][i].second;
            if(d[v]>d[u]+dist)
            {
                d[v]=d[u]+dist;
                q.push(pp(v,d[v]));
            }
        }
    }
    if(d[dest]!=999999)
        p(d[dest]);
    else
        printf("NONE\n");
    FOR(n)
    {
        a[i].clear();
    }
}
return 0;
}


