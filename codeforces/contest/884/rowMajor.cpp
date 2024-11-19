#include <bits/stdc++.h>
using namespace std;

char dp[2000001] = { 'a' }; 

void solve(){
	int n; cin >> n;

	vector<int> fs;
	for (int f=1; f*f<=n; ++f){
		if (n%f == 0){
			fs.push_back(f);
			fs.push_back(n/f);
		}
	}

	for (int i=1; i<n; ++i){
		bool has[26] = {};
		for (int f : fs){
			if (i-f >= 0){
				has[dp[i-f]-'a'] = true;
			}
		}
		bool found = false;
		for (int j=0; j<26; ++j){
			if (!has[j]){
				dp[i] = 'a'+j;
				found = true;
				break;
			}
		}
		assert(found);
	}

	dp[n] = 0;
	cout << dp << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
