#include <bits/stdc++.h>
using namespace std;

int p[200000];
int q[200000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	for (int i=0; i<n; ++i){
		cin >> p[i];
		--p[i];
	}

	for (int i=0; i<n; ++i){
		q[p[i]] = i;
	}
	set<int> w(q, q+k);
	int ans = *w.rbegin() - *w.begin();
	for (int i=0; i+k<n; ++i){
		w.erase(q[i]);
		w.insert(q[i+k]);
		ans = min(ans, *w.rbegin() - *w.begin());
	}
	cout << ans << '\n';
}
