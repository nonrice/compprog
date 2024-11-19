#include <bits/stdc++.h>
using namespace std;

char s[10001];

void solve(){
	int n, k; cin >> n >> k;
	cin >> s;
	
	if (k >= n){
		cout << "-1\n";
		return;
	}

	set<int> p;
	for (int i=0; i<=k; ++i){
		if (s[i] == '#'){
			p.insert(i);
		}
	}

	for (int i=k+1; i<n; ++i){
		if (s[i] == '#'){
			auto it = p.lower_bound(i-k-1);
			if (it == p.end()){
				break;
			}
			p.erase(it);
			p.insert(i);
		}
	}

	int ans = 0;
	for (int u : p){
		if (u+k+1 >= n){
			++ans;
		}
	}
	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--){
		solve();
	}
}
