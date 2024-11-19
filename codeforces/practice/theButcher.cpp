#include <bits/stdc++.h>
using namespace std;

map<long long, long long> m[2];

void solve(){
	m[0].clear();
	m[1].clear();

	long long area = 0;
	int n; cin >> n;
	for (int i=0; i<n; ++i){
		int a, b; cin >> a >> b;
		m[0][a] += b;
		m[1][b] += a;
		area += a*b;
	}
	
	int ans_cnt = 0;
	long long ans[4];
	for (int s=0; s<2; ++s){
		map<long long, long long>::iterator z[2] = { m[s].begin(), m[!s].begin() };
		bool cur = s;
		long long d[2] = { z[0]->first, z[0]->second };

		bool fail = false;
		while (z[cur] != m[cur].end()){
			//cout <<d[0] << ' ' << d[1] << '\n';
			if (m[!cur].count(d[!cur]) == 0){
				fail = true;
				break;
			}
			z[!cur] = m[!cur].find(d[!cur]);
			d[cur] += z[!cur]->second;
			if (d[0]*d[1] == area){
				break;
			}
			cur ^= 1;
		}

		if (!fail){
			ans[2*ans_cnt] = d[0];
			ans[1+2*ans_cnt] = d[1];
			++ans_cnt;
		}
	}
	i
	f
	cout << ans_cnt << '\n';
	for (int i=0; i<ans_cnt; ++i){
		cout << ans[2*i] << ' ' << ans[1+2*i] << '\n';
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
