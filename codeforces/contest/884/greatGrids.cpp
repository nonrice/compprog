#include <bits/stdc++.h>
using namespace std;

short m[4] = { 0b1, 0b10, 0b100, 0b1000 };
short dp[2000][2000];

void solve(){
	int n, m, k; cin >> n >> m >> k;
	map<pair<int, int>, pair<int, int>> con;
	for (int i=0; i<n; ++i){
		int a, b, c, d; cin >> a >> b >> c >> d;
		con[make_pair( a, b )] = { c, d };
	}


	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			if (i==0 && j==0){
				dp[i][j] = 0b1;
			} else if (i==0){
			
			}
		}
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
