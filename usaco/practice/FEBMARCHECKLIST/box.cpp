#include <bits/stdc++.h>
using namespace std;

int p[100000], q[100000];

void solve(){
	int n; cin >> n;
	set<int> r;
	for (int i=1; i<=n; ++i){
		r.insert(i);
	}
	for (int i=0; i<n; ++i){
		cin >> q[i];
		p[i] = q[i];
	}

	for (int i=0; i<n; ++i){
		if (r.count(p[i])){
			r.erase(p[i]);
		} else {
			p[i] = 0;
		}
	}
	for (int i=0; i<n; ++i){
		if (p[i] == 0){
			p[i] = *r.begin();
			r.erase(r.begin());
			if (p[i] > q[i]){
				cout << "-1\n";
				return;
			}
		}
	}
	for (int i=0; i<n; ++i){
		cout << p[i] << ' ';
	}
	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
