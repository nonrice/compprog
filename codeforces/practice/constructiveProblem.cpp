#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> f;
int a[200000];
bool h[200001];

void solve(){
	int n; cin >> n;

	f.clear();
	memset(h, false, n+1);

	int mex = 0;
	for (int i=0; i<n; ++i){
		cin >> a[i];
		++f[a[i]];
		if (a[i] < n){
			h[a[i]] = true;
			while (h[mex]) ++mex;
		}
	}

	if (f[mex+1] == 0){
		for (auto [k, v] : f){
			if (k>mex+1 || v > 1){
				cout << "Yes\n";
				return;
			}
		}
		cout << "No\n";
		return;
	}
	
	for (int i=find(a, a+n, mex+1)-a; i<n; ++i){
		--f[a[i]];
		if (a[i] == mex+1 && f[mex+1] == 0){
			cout << "Yes\n";
			return;
		}
		if (a[i] < mex+1 && f[a[i]] == 0){
			cout << "No\n";
			return;
		}
	}
	
	cout << "No\n";
	return;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
