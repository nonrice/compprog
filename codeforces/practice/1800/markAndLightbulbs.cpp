#include <bits/stdc++.h>
using namespace std;

int s[200001], t[200001];

void solve(){
	int n; cin >> n;
	cin >> s >> t;

	int ds=1, dt=1;
	for (int i=1; i<n; ++i){
		if (s[i] != s[i-1]) ++ds;
		if (t[i] != t[i-1]) ++dt;
	}

	if (ds == dt){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
