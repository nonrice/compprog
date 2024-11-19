#include <bits/stdc++.h>
using namespace std;
 
const int M = 1000000007;

long long binpow(long long a, long long b){
	long long ans = 1;
	while (b){
		if (b & 1) ans = ans*a%M;
		a = a*a%M;
		b >>= 1;
	}
	return ans;
}

map<int, int> f;

void solve(){
	f.clear();

	int n, m; cin >> n >> m;
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		++f[x];
	}

	long long ans = 0;
	long long cont = 1;
	int consec = 0;
	queue<pair<int, int>> win;
	for (auto [k, v] : f){
		cont = cont*v%M;
		if (win.empty() || m == 1 || k == win.back().first+1){
			++consec;
		}
		win.push({k, v});
		if (win.size() > m){
			cont = cont*binpow(win.front().second, M-2)%M;
			--consec;
			win.pop();
		}

		if (consec == m){
			ans = (ans+cont)%M;
		}
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
