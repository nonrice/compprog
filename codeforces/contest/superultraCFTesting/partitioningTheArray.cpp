#include <bits/stdc++.h>
using namespace std;

int a[200000];

void solve(){
	int n; cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];

	int ans = 1;
	for (int k=1; 2*k<=n; ++k){
		if (n % k == 0){
			int m = -1;
			for (int s=0; s<k; ++s){
				for (int c=s; c+k<n; c+=k){
					if (a[c] != a[c+k]){
						if (m == -1){
							m = abs(a[c]-a[c+k]);
						} else {
							m = gcd(m, a[c]-a[c+k]);
						}
					}
				}
			}
			if (m >= 2 || m == -1) ++ans;
		}
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
