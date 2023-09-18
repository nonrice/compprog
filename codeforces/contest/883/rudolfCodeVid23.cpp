#include <bits/stdc++.h>
using namespace std;

struct medicine {
	int c, s, t;
};

using ll = long long;

void solve(){
	int n, m; cin >> n >> m;

	string s; cin >> s;
	int start = stoi(s, nullptr, 2);

	vector<medicine> e(m);
	for (int i=0; i<m; ++i){
		cin >> e[i].t;
		string cure; cin >> cure;
		for (int i=0; i<cure.size(); ++i){
			if (cure[i] == '0') cure[i] = '1';
			else cure[i] = '0';
		}
		string side; cin >> side;
		e[i].c = stoi(cure, nullptr, 2);
		e[i].s = stoi(side, nullptr, 2);
	}

	vector<ll> dist(1025, LLONG_MAX);
	vector<bool> done(1025);
	dist[start] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.emplace(0, start);
	while (!pq.empty()){
		auto u = pq.top().second; pq.pop();
		if (done[u]) continue;
		done[u] = true;

		for (auto [c, s, t] : e){
			int v = ((u & c) | s);
			if (dist[u]+t <= dist[v]){
				dist[v] = dist[u]+t;
				pq.emplace(dist[v], v);
			}
		}
	}

	if (dist[0] == LLONG_MAX){
		cout << "-1\n";
		return;
	}
	cout << dist[0] << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
