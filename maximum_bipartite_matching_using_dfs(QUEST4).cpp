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
bool bpGraph[125][125];
int matchR[125];
bool bpm(int u,bool seen[])//same as dfs
{
    for(int v=0;v<120;v++)
    {
        if(bpGraph[u][v] && !seen[v])
        {
            seen[v]=true;
            if(matchR[v]<0 || bpm(matchR[v],seen))
            {
                matchR[v]=u;
                return true;
            }
        }
    }
    return false;
}
int maxBPM()
{
    memset(matchR,-1,sizeof matchR);
    int result=0;
    for(int u=0;u<120;u++)
    {
        bool seen[125];
        memset(seen,0,sizeof seen);
        if(bpm(u,seen))
            result++;
    }
    return result;
}
int main()
{
int i,j,l,n,m,t,T,f,p,ans,cnt,par,ele,x,y;
s(t);
while(t--)
{
    FOR(120)
        rep(j,120)
            bpGraph[i][j]=0;
    s(n);
    FOR(n)
    {
        s(x);s(y);
        bpGraph[x][y]=1;
    }
    p(maxBPM());
}


return 0;
}



