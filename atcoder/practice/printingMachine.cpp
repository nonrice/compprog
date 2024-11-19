#include <bits/stdc++.h>
using namespace std;

map<long long, vector<long long>> s;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	long long o = 0;
	for (int i=0; i<n; ++i){
		long long l, d; cin >> l >> d;
		s[l].push_back(l+d);
		o = max(o, l+d);
	}

	int ans = 0;
	for (long long t=0; t<=o; ++t){
		if (pq.empty()){
			if (s.lower_bound(t) == s.end()) break;
			t = s.lower_bound(t)->first;
		}
		for (long long r : s[t]){
			pq.push(r);
		}
		while (!pq.empty() && pq.top() < t){
			pq.pop();
		}
		if (!pq.empty()){
			pq.pop();
			++ans;
		}
	}

	cout << ans << '\n';
}
