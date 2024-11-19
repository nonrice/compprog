#include <bits/stdc++.h>
using namespace std;

char a[101], b[101];

void solve(){
	cin >> a >> b;
	int n = strlen(a);
	int m = strlen(b);

	int mx = 0;
	for (int i=0; i<m; ++i){
		int j = i;
		int k = 0;
		for (; j<m; ++j){
			k = find(a+k, a+n, b[j])-a;
			if (k == n){
				break;
			}
			++k;

		}
		mx = max(mx, j-i);
	}

	cout << n+m-mx << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
