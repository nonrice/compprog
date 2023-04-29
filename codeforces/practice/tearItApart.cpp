#include <bits/stdc++.h>
using namespace std;

char a[200001];

void solve(){
	cin >> a;
	int n = strlen(a);

	int mngap = INT_MAX;
	for (char ch = 'a'; ch <= 'z'; ++ch){
		int gap = 0;
		int mxgap = 0;
		for (int i=0; i<=n; ++i){
			if (a[i]==ch || i==n){
				mxgap = max(mxgap, gap);
				gap = 0;
			} else {
				++gap;
			}
		}
		mngap = min(mngap, mxgap);
	}

	cout << (mngap == 0 ? 0 : 32 - __builtin_clz(mngap)) << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
