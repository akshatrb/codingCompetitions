
#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
#define itr(i, n) for (i = 0; i < n; i++)
#define ritr(i, n) for (i = 0; i < n; ++i)
#define itrv(i, j, n) for (i = j; i < n; i++)
#define itreq(i, n) for (i = 0; i <= n; i++)
typedef long long ll;
typedef vector<ll> vll;
ll i, j, ind = 0;
vector<ll> v;
int test = 0;

void solve(){
    int bothPos, lPos = -1, rPos = -1;
    ll n, sum = 0; cin >> n;
    string s; cin >> s;
    vll curS(n, 0);

    itrv(i, 0, n){
        if(s[i] == 'X'){
            if (lPos > -1)
                curS[i] = (curS[lPos] + lPos + 1) % M;
            rPos = i;
        }

        else if (s[i] == 'O'){
            if (rPos > -1)
                curS[i] = (curS[rPos] + rPos + 1) % M;
            lPos = i;
        }

        else{
            bothPos = max(lPos, rPos);
            if (bothPos > -1)
                curS[i] = curS[bothPos];
        }

        sum = sum + curS[i];
        sum = sum % M;
    }
    test++;
    cout << "Case #" << test << ": " << sum << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}