#include <bits/stdc++.h>
using namespace std;

struct attack {
	int a, c;
	long long r;

	attack(int a, int c, long long r) : a(a), c(c), r(r) {}

	bool operator<(const attack& o) const {
		return r > o.r;
	}
};

int a[200000], c[200000];

void solve(){
	int h, n; cin >> h >> n;
	for (int i=0; i<n; ++i){
		cin >> a[i];
	}
	for (int i=0; i<n; ++i){
		cin >> c[i];
	}

	priority_queue<attack> q;
	for (int i=0; i<n; ++i){
		q.emplace(a[i], c[i], 0);
	}
	
	long long t = 0;
	while (h > 0){
		auto [a, c, r] = q.top(); q.pop();
		t = r;
		h -= a;
		q.emplace(a, c, t+c);
	}

	cout << t+1 << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
