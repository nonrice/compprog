#include <bits/stdc++.h>
using namespace std;

char s[200001];

void solve(){
	int n; cin >> n;
	cin >> s;

	if (n%2){
		cout << "-1\n";
		return;
	}

	int f[26] = {};
	for (int i=0; i<n; ++i) ++f[s[i]-'a'];
	if (*max_element(f, f+26) > n/2){
		cout << "-1\n";
		return;
	}

	int fm[26] = {};
	int m = 0;
	for (int i=0; i<n/2; ++i){
		if (s[i] == s[n-i-1]){
			++m;
			++fm[s[i]-'a'];
		}
	}

	int mx = *max_element(fm, fm+26);

	// max(0, mx-(m-mx)) + (m - max(0, (mx-(m-mx))) + 1) / 2
	
	cout << max(0, 2*mx-m) + (m-max(0, 2*mx - m) + 1)/2 << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}

