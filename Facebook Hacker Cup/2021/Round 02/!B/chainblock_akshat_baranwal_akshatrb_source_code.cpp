#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
#define itr(i, n) for (i = 0; i < n; i++)
#define ritr(i, n) for (i = 0; i < n; ++i)
#define itrv(i, x, n) for (i = x; i < n; i++)
#define itreq(i, n) for (i = 0; i <= n; i++)
#define itrveq(i, x, n) for (i = x; i <= n; i++)
typedef long long ll;
typedef vector<ll> vll;
map<int, int> maxChainBlock;
ll i, j, ind = 0;
vector<ll> v;
int test = 0, ans, occur[800001];

void merge(vector<map<ll,ll>> &state, ll a, ll b, vector<ll>&parent){
    ll pp = b;
    if(state[parent[a]].size()>state[parent[b]].size()){
        swap(a,b);
    }
    for(auto ele:state[parent[a]]){
        state[parent[b]][ele.first] += ele.second;
    }
    parent[pp] = parent[b];
}

void solve()
{
        ll n;
    cin>>n;
    vector<vector<ll> > edges(n);
    vector<ll> count(n+1);
    vector<ll> deg(n);
    for(ll i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        deg[x]++;
        deg[y]++;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<ll> freq(n);
    for(auto &ele:freq){
        cin>>ele;
        count[ele]++;
    }
    vector<map<ll,ll>> state(n);
    vector<ll> parent(n);
    for(ll i=0;i<n;i++){
        state[i][freq[i]] = 1;
        parent[i] = i;
    }

    stack<ll> s;
    for(ll i=0;i<n;i++){
        if(deg[i] == 1){
            s.push(i);
        }
    }
    //debug(deg)
    //debug(s)
    ll ans = 0;
    while(!s.empty()){
        ll top = s.top();
        s.pop();
        if(deg[top]!=1)
            continue;
        ll check = true;
        for(auto ele:state[parent[top]]){
            if(ele.second!=count[ele.first]){
                check = false;
                break;
            }
        }
        deg[top] = 0;
        ll pa = -1;
        for(auto ele:edges[top]){
            if(deg[ele]>0){
                pa = ele;
                break;
            }
        }
        deg[pa]--;
        if(deg[pa]==1)
            s.push(pa);
        if(!check){
            merge(state,top,pa,parent);
            
        }else
            ans++;
    }
    test++;
    cout << "Case #" << test << ": " << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
