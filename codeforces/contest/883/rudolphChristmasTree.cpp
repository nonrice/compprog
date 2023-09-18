#include <bits/stdc++.h>
using namespace std;

long double a[200000];

void solve(){
	int n; cin >> n;

	long double d, h; cin >> d >> h;
	for (int i=0; i<n; ++i) cin >> a[i];

	sort(a, a+n, greater<long double>());

	long double zero = 0; // I CAN'T FIND THE SUFFIX
	long double ans = 0;
	long double bottom = numeric_limits<double>::max();
	for (int i=0; i<n; ++i){
		long double w1 = max(zero, d*(a[i]-bottom)/h);
		ans += (w1 + d)/2 * (h - min(h, max(zero, a[i]-bottom)));
		bottom = a[i] - h;
	}

	cout << fixed;
    cout << setprecision(10);
	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
