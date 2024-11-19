#include <bits/stdc++.h>
using namespace std;

struct seg {
	int l, r;
	
	bool operator<(const seg& o) const {
		return r < o.r;
	}
};
seg s[100000];

constexpr int M = 1000000007;
int dp[100000];
int p2[100001] = { 1 };

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
#ifndef LOCAL
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
#endif

	int n; cin >> n;
	for (int i=0; i<n; ++i){
		cin >> s[i].l >> s[i].r;
		p2[i+1] = p2[i]*2%M;
	}

	sort(s, s+n);
	int ans = 0;
	for (int i=0; i<n; ++i){
		dp[i] = 1;
		for (int j=0; j<i; ++j){
			if (s[j].r < s[i].l){
				dp[i] = ((dp[i] + dp[j])%M + p2[j])%M; 
			} else if (s[j].l < s[i].l && s[j].r > s[i].l){
				dp[i] = (dp[i] + dp[j])%M;
			} else if (s[j].l > s[i].l){
				dp[i] = dp[i]*2%M;
			}
		}
		ans = (ans + dp[i])%M;
	}

	cout << ans << '\n';
}
