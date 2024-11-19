#include <bits/stdc++.h>
using namespace std;


int a[50001];
char m[51][52];
int d[50001];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	for (int i=1; i<=n; ++i) cin >> a[i];
	for (int i=1; i<=k; ++i) cin >> (m[i]+1);

	fill(d+1, d+n+1, INT_MAX);
	d[1] = 0;
	queue<int> q({ 1 });
	vector<bool> in(n+1);
	in[1] = true;

	while (!q.empty()){
		int u = q.front();
		q.pop();
		in[u] = false;
		for (int v=1; v<=n; ++v) if (m[a[u]][a[v]] == '1'){
			int w = abs(v-u);
			if (d[u] != INT_MAX && d[u] + w < d[v]){
				d[v] = d[u] + w;
				if (!in[v]){
					q.push(v);
					in[v] = true;
				}
			}
		}
	}

	cout << (d[n]==INT_MAX ? -1 : d[n]) << '\n';
}
