#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> cache;

int dp(int a, int b){
	if (a == 0) return 0;

	if (cache.count({a, b})) return cache[{a, b}];
	if (a > b && b > 0){
		if (a/b%2) return cache[{a, b}] = (dp(b, a%b) + a/b + (a/b - 1)/2) % 3;
		else return cache[{a, b}] = (dp(a%b, b) + a/b+1 + (a/b - 1)/2) % 3;
	}
	return cache[{a, b}] = (dp(b, abs(a-b)) + 1)%3;
}

int a[100000], b[100000];

void solve(){
	int n; cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int i=0; i<n; ++i) cin >> b[i];

	int k = 0;
	while (k<n && a[k]==0 && b[k]==0) ++k;

	if (k==n){
		cout << "YES\n";
		return;
	}

	int c = dp(a[k], b[k]);
	for (int i=1; i<n; ++i){
		if (a[i] == 0 && b[i] == 0){
			continue;
		}

		if (dp(a[i], b[i]) != c){
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
