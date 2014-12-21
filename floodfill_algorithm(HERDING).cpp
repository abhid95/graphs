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
int grid[1005][1005];
char a[1005][1005];
int n,m,cnt;
void floodfill(int i,int j)
{
    if(i>=0 && j>=0 && i<n && j<m)
    {
        if(grid[i][j])
        {
            cnt=grid[i][j];
            return;
        }
        grid[i][j]=cnt;
        if(a[i][j]=='S') floodfill(i+1,j);
        else if(a[i][j]=='N') floodfill(i-1,j);
        else if(a[i][j]=='W') floodfill(i,j-1);
        else if(a[i][j]=='E') floodfill(i,j+1);
        grid[i][j]=cnt;
    }
}
int main()
{
int i,j,l,t,T,f,p,ans,par,ele;
char x;
int trap=0;
scanf("%d%d",&n,&m);
FOR(n) scanf("%s",a[i]);
for(i=0;i<n;i++)
    for(j=0;j<m;j++)
        if(!grid[i][j])
        {
            cnt=trap+1;
            floodfill(i,j);
            if(cnt>trap) trap++;
        }
p(trap);

return 0;
}



