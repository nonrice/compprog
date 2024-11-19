#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	vector<pair<int, int>> ans;
	for (int s=2; s<=600; ++s){
		for (int a=1; a<s; ++a){
			if (gcd(a, s-a) == 1){
				ans.emplace_back(a, s-a);
			}
		}
	}

	int t; cin >> t;
	while (t--){
		int n; cin >> n; --n;
		cout << ans[n].first << ' ' << ans[n].second << '\n';
	}
}
