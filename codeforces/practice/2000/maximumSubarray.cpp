#include <bits/stdc++.h>
using namespace std;

//long long dp[200001][21], a[200001];
//long long dp2[200001];

void solve(){
	int n, k, x; cin >> n >> k >> x;

	vector<vector<long long>> dp(n+1, vector<long long>(k+1));
	vector<long long> a(n+1);
	vector<long long> dp2(n+2);
	
	for (int i=1; i<=n; ++i){
		cin >> a[i];
		a[i] -= x;
	}
	
	if (x <= 0){
		dp[0][0] = 0;
		int l = 0;
		long long ans = 0;
		for (int i=1; i<=n; ++i){
			dp[i][0] = max(0LL, dp[i-1][0]+a[i]);
			if (dp[i][0] == 0) l = 0;
			else ++l;

			long long bst_diff = LLONG_MIN;
			int cnt = max(0, k-(n-l));
			for (int s=0; s<=cnt; ++s){
				for (int p=i-l+1; p<=i-l+s+1; ++p){
					for (int t=i; t>=i-(cnt-s); --t){
						long long diff = 0;
						bool shorten = true;
						for (int q=i-l+1; q<i-l+s+1; ++q){
							if (q==p) shorten = false;
							if (shorten) diff -= a[q]; 
							else diff -= abs(2*x);
						}
						shorten = true;
						for (int q=i; q>i-(cnt-s); --q){
							if (q==t) shorten=false;
							if (shorten) diff -= a[q]; 
							else diff -= abs(2*x);
						}
						bst_diff = max(bst_diff, diff);
					}
				}
			}
			ans = max(ans, dp[i][0]+bst_diff);
		}
		cout << ans << '\n';
		return;
	}

	dp[0][0] = 0;
	for (int i=1; i<=n; ++i) dp[i][0] = max(0LL, dp[i-1][0]+a[i]);

	for (int j=1; j<=k; ++j){
		dp[0][j] = 0;
		long long bst = dp[j-1][j-1];
		for (int i=j; i<=n; ++i){
			cout << '(' << bst << ' ' << a[i] << ") ";
			dp[i][j] = bst + a[i] + 2*x;
			bst = max(bst+a[i], dp[i][j-1]);
		}
		cout << '\n';
	}
	cout << "---\n";

	for (int j=0; j<=k; ++j){
		for (int i=0; i<=n; ++i) cout << dp[i][j] << ' ';
		cout << '\n';
	}
	

	dp2[n+1] = 0;
	long long ans = 0;
	for (int i=n; i>=0; --i){
		dp2[i] = max(0LL, dp2[i+1]+a[i]);
		ans = max(ans, dp[i][k] + dp2[i+1]);
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
