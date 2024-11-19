#include <bits/stdc++.h>
using namespace std;

long long a[200000], p[200000];

void solve(){
	int n, m; cin >> n >> m; --m;
	for (int i=0; i<n; ++i) cin >> a[i];

	p[0] = a[0];
	for (int i=1; i<n; ++i) p[i] = a[i] + p[i-1];

	int ans = 0;

	priority_queue<long long> pq;
	long long vp = p[m];
	for (int i=m; i>=0; --i){
		while (vp > p[i]){
			++ans;
			vp -= 2*pq.top();
			pq.pop();
		}
		pq.push(a[i]);
	}

	vp = p[m];
	priority_queue<long long, vector<long long>, greater<long long>> pq2;
	for (int i=m+1; i<n; ++i){
		pq2.push(a[i]);
		while (vp > p[i]){
			++ans;
			vp += 2*pq2.top();
			pq2.pop();
		}
	}

	cout << ans << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
