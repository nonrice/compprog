#include <bits/stdc++.h>
using namespace std;

vector<int> p({ 1 });
long long dp[10001] = { 1 };

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

#ifndef LOCAL
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
#endif

	int n, m; cin >> n >> m;
	for (int i=2; i<=n; ++i){
		bool prime = true;
		for (int f=2; f*f<=i; ++f){
			if (i%f == 0){
				prime = false;
				break;
			}
		}
		if (prime){
			p.push_back(i);
		}
	}

	for (int t : p){
		for (int i=t; i<=n; ++i){
			dp[i] = (dp[i] + dp[i-t]*t%m)%m;
		}
	}

	for (int i=0; i<=n; ++i) cout << dp[i] << ' ';
	cout << '\n';
}
