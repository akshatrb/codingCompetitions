#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;
int i, j;
#define itr(i, n) for (i = 0; i < n; i++)
#define ritr(i, n) for (i = 0; i < n; ++i)
#define itrv(i, x, n) for (i = x; i < n; i++)
#define itreq(i, n) for (i = 0; i <= n; i++)
#define ll long long

bool vowHelper(char c){
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return true;
	return false;
}
void solve(){
	string s; cin >> s;
	ll v=0, c=0, a[26] = {0}, n = s.size(), flag=0, sum=0, ans = INT_MAX;

	if (n == 1){
		cout << "0" << endl;
		return;
	}

	else{
		itr(i, n - 1){
			if (s[i] != s[i + 1]){
				flag = 1;
				break;
			}
		}
		if (flag == 0){
			cout << "0" << endl;
			return;
		}
	}

	itr(i, n){
		a[s[i] - 'A'] += 1;
		bool temp = vowHelper(s[i]);
		if (temp)
			v++;
		else
			c++;
	}

	if (v > 0 && c == 0){
		cout << v << endl;
		return;
	}

	else if (v == 0 && c > 0){
		cout << c << endl;
		return;
	}

	itr(i, 26){
		if (a[i] > 0){
			sum=0;
			itr(j, 26){
				if (i != j && a[j] > 0){
					if ((vowHelper(char(i + 'A')) && vowHelper(char(j + 'A'))) || (!vowHelper(char(i + 'A')) && !vowHelper(char(j + 'A'))))
						sum += (2 * a[j]);

					else if ((vowHelper(char(i + 'A')) && !vowHelper(char(j + 'A'))) || (!vowHelper(char(i + 'A')) && vowHelper(char(j + 'A'))))
						sum += a[j];
				}
			}
			ans = min(ans, sum);
		}
	}
	cout << ans << endl;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t, xx=0; cin >> t;
	while(t--){
	    xx++;
		cout << "Case #" << xx << ": "; solve();
	}
	return 0;
}
