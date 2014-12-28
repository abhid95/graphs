// disjoint data structure to find loop or cycle
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
#define s(t) scanf("%lld",&t)
#define p(t) printf("%lld\n",t)
using namespace std;
ll parent[100005],n;
vector<int> g[100005];
ll find(ll parent[],ll i)
{
    if(parent[i]==-1)
        return i;
    return find(parent,parent[i]);
}
void Union(ll parent[],ll x,ll y)
{
    ll xset=find(parent,x);
    ll yset=find(parent,y);
    parent[xset]=yset;
}
ll isCycle()
{
    memset(parent,-1,sizeof parent);
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<g[i].size();j++)
        {
            ll x=find(parent,i);
            ll y=find(parent,g[i][j]);

            if(x==y)
                return 1;
            Union(parent,x,y);
        }
    }
    return 0;
}
int main()
{
ll i,j,l,m,t,T,f,p,ans,cnt,par,ele,u,v;
char x;
s(n);
s(m);
FOR(m)
{
    s(u);
    s(v);
    u--;
    v--;
    g[u].pb(v);

}
if(isCycle())
        printf("NO\n");
    else
        printf("YES\n");
return 0;
}



