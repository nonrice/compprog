#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	string s; cin >> s;

	array<array<int, 26>, 26> f = {};
	array<int, 26> f1 = {}, f2 = {};
	for (int i=0; i+1<n; i += 2){
		++f[s[i]-'a'][s[i+1]-'a'];
		++f1[s[i]-'a'];
		++f2[s[i+1]-'a'];
	}

	if (n%2){
		cout << "ehh\n";
	} else {
		int ans = INT_MAX;
		for (int i=0; i<26; ++i){
			for (int j=0; j<26; ++j){
				ans = min(ans, 2*f[i][j] - f1[i] - f2[j]);
			}
		}
		cout << ans << '\n';

	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
