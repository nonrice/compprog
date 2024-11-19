#include <bits/stdc++.h>
using namespace std;

int l[200000];
int m1[200000], m2[200000];

void solve(){
	int n, k; cin >> n >> k;

	fill(m1, m1+k, 0);
	fill(m2, m2+k, 0);
	fill(l, l+k, 0);

	for (int i=1; i<=n; ++i){
		int p; cin >> p; --p;
		int d = i-l[p]-1;
		if (d >= m1[p]){
			m2[p] = m1[p];
			m1[p] = d;
		} else if (d > m2[p]){
			m2[p] = d;
		}
		l[p] = i;
	}

	int ans = INT_MAX;
	for (int i=0; i<k; ++i){
		int d = n-l[i];
		if (d >= m1[i]){
			m2[i] = m1[i];
			m1[i] = d;
		} else if (d > m2[i]){
			m2[i] = d;
		}
	
		ans = min(ans, max(m1[i]/2, m2[i]));
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
