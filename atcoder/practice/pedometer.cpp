#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	map<int, int> l;
	const int s = accumulate(a.begin(), a.end(), 0LL) % m;
	int p = 0;
	long long ans = 0;
	for (int i=0; i<n; ++i){
		p = (p + a[i]) % m;
		ans += l[p];
		if (i != n-1){
			ans += l[(p-s+m)%m];
		}
		++l[p];
	}
	cout << ans << '\n';
}
