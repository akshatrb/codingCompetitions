#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
#define itr(i, n) for (i = 0; i < n; i++)
#define ritr(i, n) for (i = 0; i < n; ++i)
#define itrv(i, x, n) for (i = x; i < n; i++)
#define itreq(i, n) for (i = 0; i <= n; i++)
typedef long long ll;
typedef vector<ll> vll;
ll i, j, ind = 0;
vector<ll> v;
int test = 0;

void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<pair<int, int>> a, b;
    ritr(i, m)
    {
        int reactt;
        cin >> reactt;
        a.insert({reactt, 1});
    }

    int ans = 0;
    while (n)
    {
        b.clear();
        vector<int> r;
        ritr(i, m)
        {
            int reactt;
            cin >> reactt;
            if (a.find({reactt, 0}) == a.end())
            {

                r.push_back(reactt);
            }

            else
            {
                a.erase(a.find({reactt, 0}));
                b.insert({reactt, 0});
                continue;
            }
        }
        vector<int> r2;
        for (auto reactt : r)
        {
            if (a.find({reactt, 1}) == a.end())
            {
                r2.push_back(reactt);
            }
            else
            {
                a.erase(a.find({reactt, 1}));
                b.insert({reactt, 1});
                continue;
            }
        }
        for (auto i : a)
        {
            b.insert({r2.back(), 0});
            r2.pop_back();
            ans += i.second == 0;
        }
        a.swap(b);
        n--;
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
