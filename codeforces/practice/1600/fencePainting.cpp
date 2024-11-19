#include <bits/stdc++.h>
using namespace std;

int a[100000];
map<int, queue<int>> rem;
bool has[100001];
int c[100000];

void solve(){
	int n, m; cin >> n >> m;

	rem.clear();
	memset(has, false, n+1);

	for (int i=0; i<n; ++i) cin >> a[i];

	for (int i=0; i<n; ++i){
		int bi; cin >> bi;
		if (a[i] != bi) rem[bi].push(i+1);
		has[bi] = true;
	}

	bool fail = false;
	vector<int> ans;

	for (int i=0; i<n; ++i) cin >> c[i];

	for (int i=0; i<n; ++i){
		if (!fail){
			if (!rem[c[i]].empty()){
				ans.push_back(rem[c[i]].front);
				rem[c[i]].pop();
				if (rem[c[i]].empty()){
					rem.erase(c[i]);
				}
			} else if (!has[c[i]]){
				if (!rem.empty()){
					ans.
				}
			}
		}
	}

}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
