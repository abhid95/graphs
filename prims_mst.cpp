#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>

ll n, m, i, u, v, c, cost[100005], t;
set< pii > :: iterator it;
ll sum, wt;
vector< pii > g[100005];
set< pii > st;
int main() {
    cin>>n>>m;
    for(i = 0; i < m; i++) {
        cin>>u>>v>>t;
        u--;v--;
        c = 0;
        if(t) cin>>c;
        g[u].push_back(pii(v, c));
        g[v].push_back(pii(u, c));
    }
    cost[0] = 0;
    for(i = 1; i < n; i++) {
        cost[i] = 1e9;
        st.insert(pii(cost[i], i));
    }
    st.insert(pii(cost[0], 0));
    sum = 0;
    while(!st.empty()) {
        it = st.begin();
        pii p = *it;
        st.erase(it);
        wt = p.first;
        sum += wt;
        u = p.second;
        //cout<<u<<" "<<wt<<endl;
        for(i = 0; i < g[u].size(); i++) {
            v = g[u][i].first;
            if(cost[v] > g[u][i].second) {
                ll prv = cost[v];
                cost[v] = g[u][i].second;
                if(st.find(pii(prv, v))!=st.end()) {
                    st.erase(pii(prv, v));
                    st.insert(pii(cost[v], v));
                }
            }
        }
    }
    cout<<sum<<endl;


    return 0;
}
