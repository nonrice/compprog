#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}

	for (int i=1; i<n; ++i){
		if (a[i] <= a[i-1]){
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	solve();
}
