#include<bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
#define itr(i, n) for (i = 0; i < n; i++)
#define ritr(i, n) for (i = 0; i < n; ++i)
#define itrv(i, x, n) for (i = x; i < n; i++)
#define itreq(i, n) for (i = 0; i <= n; i++)
#define ll long long
ll i, j, ind = 0;
vector<ll> v;
int test=0;

void solve()
{
    int n, sum=0; cin>>n;
    string s; cin>>s;
    char cur = 'A';
    itr(i, s.size()){
        if(s[i]=='O' or s[i]=='X'){
            if(cur=='A') cur=s[i];
            else{
                if(cur!=s[i]){
                    sum++;
                    cur=s[i];
                }
            }
        }
    }
    test++;
    cout<<"Case #"<<test<<": "<<sum<<endl;
}

int main() 
{
    ios_base::sync_with_stdio(false) ; cin.tie(nullptr); 
    int t; cin >> t ;
    while(t--) solve();
    return 0;
}   

