#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
int i, j, ind=0;
#define itr(i, n) for (i = 0; i < n; i++)
#define ritr(i, n) for (i = 0; i < n; ++i)
#define itrv(i, x, n) for (i = x; i < n; i++)
#define itreq(i, n) for (i = 0; i <= n; i++)
#define ll long long

void solve(){
    ind++;
    ll X = 0, O = 0, period = 0, pos = INT_MAX, n,  count = 0;
    
    cin >> n;

    vector<int> matCol(n, -1), matRow(n, -1);
    vector<vector<char>> mat(n, vector<char>(n));
        itr(i, n){
            itr(j, n){
                cin >> mat[i][j];
            }
        }

        itr(i, n){
            itr(j, n){
                if (mat[j][i] == '.')
                    period++;
                else if (mat[j][i] == 'X')
                    X++;
                else
                {
                    O = 1;
                    break;
                }
            }
            if (O != 1)
            {
                pos = min(pos, period);
                matCol[i] = period;
            }
            period = 0, X=0, O=0;
        }
        
        itr(i,n){
            itr(j, n){
                if (mat[i][j] == '.')
                    period++;
                else if (mat[i][j] == 'X')
                    X++;
                else
                {
                    O = 1;
                    break;
                }
            }
            if (O != 1)
            {
                pos = min(pos, period);
                matRow[i] = period;
            }
            period = 0, X=0, O=0;
        }

        if (pos == INT_MAX)
        {
            cout << "Case #" << ind << ": Impossible"<<endl;
            return;
        }

        itr(i, n){
            if (matCol[i] == 1 && matRow[i] == 1 && mat[i][i] == '.')
            {
                count++;
                continue;
            }
            if (matRow[i] == pos)
                count++;
            if (matCol[i] == pos)
                count++;
        }
        cout << "Case #" << ind << ": " << pos << ' ' << count << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
}
