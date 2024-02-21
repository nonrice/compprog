#include <bits/stdc++.h>
using namespace std;

constexpr char p[6][4] = { "abc", "acb", "bac", "bca", "cab", "cba" };
char s[200001];
int m[200001][6];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, q; cin >> n >> q;
	cin >> s;

	for (int i=0; i<n; ++i){
		for (int j=0; j<6; ++j){
			m[i+1][j] = m[i][j] + (s[i] != p[j][i%3]);
		}
	}

	while (q--){
		int l, r; cin >> l >> r;
		int ans = INT_MAX;
		for (int i=0; i<6; ++i){
			ans = min(ans, m[r][i] - m[l-1][i]);
		}
		cout << ans << '\n';
	}
}
