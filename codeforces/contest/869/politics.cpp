#include <bits/stdc++.h>
using namespace std;

char a[100][101];
bool out[100];

void solve(){
	int n, k; cin >> n >> k;

	memset(out, false, n);

	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	for (int i=0; i<k; ++i){
		int x=0, y=0;
		for (int j=0; j<n; ++j){
			if (!out[j]){
				if (a[j][i]==a[0][i]) ++x;
				else ++y;
			}
		}

		for (int j=0; j<n; ++j) if (a[j][i] != a[0][i]) out[j] = true;
	}

	cout << count(out, out+n, false) << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
