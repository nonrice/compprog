#include <bits/stdc++.h>
using namespace std;

void solve(){
	unsigned int n, m; cin >> n >> m;
	
	unsigned int ans = 0;
	for (int i=0; i<32; ++i){
		if (((n>>i) & 1) == 0){
			if (((n>>i)<<i) + (1<<i) - n <= m){
				ans += 1<<i;
			} else if ((1<<i) < n && (n<<(31-i)>>(31-i)) + 1 <= m){
				ans += 1<<i;
			}
		} else {
			ans += 1<<i;
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
