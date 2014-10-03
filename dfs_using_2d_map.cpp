#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<stack>
#include<ctype.h>
#include<queue>
#include<map>
#include<list>
#include<string.h>
#include<algorithm>
#define MAX 1000000007
#define FOR(n) for(i=0;i<n;i++)
using namespace std;
long int mx(long int a[],long int k)
{
    long int i,m;
    m=0;
    FOR(k)
        if(a[i]>m)
            m=a[i];
    return m;
}
void dfs(int it,int visited[],map<int,vector<int> > m)
{
    int i;
    visited[it]=1;
    cout<<it<<endl;
    for(i=0;i<m[it].size();i++)
    {
        if(!visited[m[it][i]])
        {
            dfs(m[it][i],visited,m);
        }
    }

}
int main()
{
int V,n,i,u,v,visited[5]={0},s;
map < int,vector<int> > m;
cin>>V;
cin>>n;
FOR(n)
{
    cin>>u>>v;
    m[u].push_back(v);
}
/*q.push(2);
visited[2]=1;
while(!q.empty())
{
    s=q.front();
    cout<<s<<" ";
    q.pop();

    for(i=0;i<m[s].size();i++)
    {
        if(!visited[m[s][i]])
        {
            visited[m[s][i]]=1;
            q.push(m[s][i]);
        }
    }
    cout<<endl;
}
*/
dfs(2,visited,m);

return 0;
}


