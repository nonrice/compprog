#include <bits/stdc++.h>
using namespace std;

int a[10];
int s[10];

void solve(){
	int n; cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];

	memset(s, 0, sizeof(s));
	while (1){
		int sum = 0;
		for (int i=0; i<n; ++i){
			if (s[i] == 1) sum += a[i];
			else if (s[i] == 2) sum -= a[i];
		}
		
		for (int i=0; i<n; ++i){
			if (sum == a[i] && s[i] == 0){
				cout << "YES\n";
				return;
			}
		}
		
		for (int i=0; i<n; ++i){
			if (++s[i] == 3){
				s[i] = 0;
				if (i == n-1) goto done;
			} else {
				break;
			}
		}
	}

done:
	cout << "NO\n";
	return;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
