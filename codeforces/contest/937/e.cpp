#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	string s; cin >> s;

	for (int l=1; l<=n; ++l){
		if (n % l == 0){
			map<string, int> m;
			for (int i=0; i<n; i+=l){
				m[s.substr(i, l)]++;
			}
			if (m.size() == 1){
				cout << l << '\n';
				return;
			}
			if (m.size() > 2 || min(m.begin()->second, (++m.begin())->second) != 1){
				continue;
			}
			bool d = false;
			string x = m.begin()->first;
			string y = (++m.begin())->first;
			for (int i=0; i<l; ++i){
				if (x[i] != y[i]){
					if (d){
						goto not_work;
					}
					d = true;
				}
			}
			cout << l << '\n';
			return;
not_work:
			continue;
		}
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
