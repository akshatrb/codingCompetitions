#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
#define itr(i, n) for (i = 0; i < n; i++)
#define ritr(i, n) for (i = 0; i < n; ++i)
#define itrv(i, x, n) for (i = x; i < n; i++)
#define itreq(i, n) for (i = 0; i <= n; i++)
#define ll long long
ll i, j, ind = 0;
vector<ll> v;

ll dfs(vector<vector<ll>> &G, vector<ll> &Gval, vector<bool> &visited, ll source, ll K)
{
    visited[K] = true;
    ll value = 0;
    if (source == K)
    {
        for (auto x : G[K])
        {
            if (!visited[x])
            {
                value = dfs(G, Gval, visited, source, x);
                v.push_back(value);
            }
        }
        return 1;
    }
    else if (G[K].size() == 1)
        return Gval[K];
    else
    {
        for (auto x : G[K])
        {
            if (!visited[x])
                value = max(value, Gval[K] + dfs(G, Gval, visited, source, x));
        }
    }
    return value;
}

void solve()
{
    v.clear();
    ll n, x, y, j = 1;
    cin >> n;
    vector<vector<ll>> G(n + 1);
    vector<ll> Gval(n + 1);
    vector<bool> visited(n + 1, false);

    itr(i, n)
        cin >> Gval[i+1];

    itr(i, n-1)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    ll ans = dfs(G, Gval, visited, 1, 1);

    if (v.size() == 1)
    {
        cout << "Case #" << j << ": " << v[0] + Gval[1] <<  endl;
        j++;
    }
    else
    {
    ll xxa = 0, xxb = 0, ind = -1;
        
    itr(i, v.size())
    {
        if (v[i] > xxa)
        {
            xxa = v[i];
            ind = i;
        }
    }

    itr(i, v.size())
    {
        if (v[i] > xxb && i != ind)
            xxb = v[i];
    }
    cout << "Case #" << j << ": " << xxa + xxb + Gval[1] << endl;
    j++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while (t--)
    {
        solve();
    }
}
