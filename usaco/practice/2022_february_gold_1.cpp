#include <bits/stdc++.h>
using namespace std;

int n;
bool adj[19][19];

#define setb(m, i) ((m) | (1 << (i)))
#define unsetb(m, i) ((m) ^ (1 << (i)))
#define getb(m, i) (((m) >> (i)) & 1)
int dp(uint32_t m, int h, int t){
	//cout << bitset<16>(m) << ' '<< h << ' '<< t << '\n';
	
	// Base: empty subgraph
	if (m == 0 && h==-1){
		return 1;
	}

	// Finish redistribution: transition from any dp' when h'->t' and m'=m
	if (h == -1){
		int ans = 0;
		for (int u=1; u<=n; ++u){
			for (int v=1; v<=n; ++v){
				if (adj[u][v]){
					ans += dp(m, u, v);
				}
			}
		}
		return ans;
	}

	// Invalid DP
	if (!getb(m, h) || !getb(m, t)){
		return 0;
	}

	// New chain: transition from finished redistribution
	if (h == t){
		return dp(unsetb(m, h), -1, -1);
	}

	// Extend chain: transition from shorter chain
	int ans = 0;
	for (int u=1; u<=n; ++u){
		if (adj[u][h] && getb(m, u)){
			ans += dp(unsetb(m, h), u, t);
		}
	}
	return ans;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	cin >> n;
	for (int u=1; u<=n; ++u){
		bool c = true;
		for (int i=1; i<=n; ++i){
			int v; cin >> v;
			adj[u][v] = c;
			if (v == u){
				c = false;
			}
		}
	}

	cout << dp(0b00010, -1, -1) << '\n';
	cout << dp(0b10000, -1, -1) << '\n';
	cout << dp(0b01000, -1, -1) << '\n';
	cout << dp(0b01100, -1, -1) << '\n';
	cout << dp(0b11110, -1, -1) << '\n';
}
