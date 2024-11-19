#include <bits/stdc++.h>
using namespace std;

long long a[100002];

void solve(){
	int n, m, d; cin >> n >> m >> d;
	a[0] = 1;
	a[m+1] = n+1;
	for (int i=1; i<=m; ++i) cin >> a[i];
	
	sort(a+1, a+m+1);

	int eat = m + (a[1] != 1);
	for (int i=1; i<=m+1; ++i) eat += (a[i]-a[i-1]-1)/d;

	int ans = 0;
	for (int i=1; i<=m; ++i){
		if (a[i] == 1) continue;
		if ((a[i+1]-a[i-1]-1)/d == (a[i]-a[i-1]-1)/d + (a[i+1]-a[i]-1)/d){
			++ans;
		}
	}

	cout << eat-(ans>0) << ' ' << ((ans>0) ? ans : m) << '\n';

}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
