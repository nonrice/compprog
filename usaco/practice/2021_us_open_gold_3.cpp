#include <bits/stdc++.h>
using namespace std;

constexpr long long M = 1000000007;

int n;
long long x[40], y[40];
int c[40][40][40];
long long f[41] = { 1 };
long long fi[41] = { 1 };

inline bool cont(int t, int u, int v, int p){
	long long a = abs(x[t]*y[u] + x[u]*y[v] + x[v]*y[t] - y[t]*x[u] - y[u]*x[v] - y[v]*x[t]);
	long long a1 = abs(x[t]*y[u] + x[u]*y[p] + x[p]*y[t] - y[t]*x[u] - y[u]*x[p] - y[p]*x[t]);
	long long a2 = abs(x[v]*y[u] + x[u]*y[p] + x[p]*y[v] - y[v]*x[u] - y[u]*x[p] - y[p]*x[v]);
	long long a3 = abs(x[t]*y[v] + x[v]*y[p] + x[p]*y[t] - y[t]*x[v] - y[v]*x[p] - y[p]*x[t]);
	return a1+a2+a3==a;
}

inline long long P(int n, int k){
	long long ans = 1;
	for (; k>0; --k, --n){
		ans = ans*n%M;
	}
	return ans;
}

map<tuple<int, int, int, int>, long long> mem;
long long dp(int t, int u, int v, int i){
	if (mem.count({ t, u, v, i })){
		return mem[{ t, u, v, i }];
	}
	if (i<0 || i>c[t][u][v]){
		return mem[{ t, u, v, i }] = 0;
	}
	long long ans = 6*P(c[t][u][v], i)%M;
	for (int w=0; w<n; ++w){
		if (w != t && w != u && w != v && cont(t, u, v, w)){
			for (int j=0; j<i; ++j){
				ans = (ans + P(c[t][u][v]-j-1, i-j-1)*dp(w, u, v, j)%M) % M;
				ans = (ans + P(c[t][u][v]-j-1, i-j-1)*dp(t, w, v, j)%M) % M;
				ans = (ans + P(c[t][u][v]-j-1, i-j-1)*dp(t, u, w, j)%M) % M;
			}
		}
	}
	return mem[{ t, u, v, i }] = ans;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i=0; i<n; ++i){
		cin >> x[i] >> y[i];
	}

	int q=-1, r=-1, s=-1;
	for (int t=0; t<n; ++t){
		for (int u=0; u<n; ++u) if (u != t){
			for (int v=0; v<n; ++v) if (v != u && v != t){
				for (int w=0; w<n; ++w) if (w != u && w != v && w != t){
					c[t][u][v] += cont(t, u, v, w);
				}
				if (c[t][u][v] == n-3){
					q=t, r=u, s=v;
				}
			}
		}
	}

	if (q == -1){
		cout << "0\n";
	} else {
		cout << dp(q, r, s, n-3) << '\n';
	}
}
