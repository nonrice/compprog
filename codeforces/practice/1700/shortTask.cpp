#include <bits/stdc++.h>
using namespace std;

constexpr int MXC = 10000000;

int d[MXC+1], ans[MXC+1];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	for (int b=1; b<=MXC; ++b){
		for (int i=b; i<=MXC; i+=b){
			d[i] += b;
		}
	}

	for (int i=1; i<=MXC; ++i){
		if (d[i]<=MXC && ans[d[i]] == 0) ans[d[i]] = i;
	}

	int n; cin >> n;
	while (n--){
		int c; cin >> c;
		if (ans[c] == 0){
			cout << "-1\n";
		} else {
			cout << ans[c] << '\n';
		}
	}
}
