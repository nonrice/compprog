#include <bits/stdc++.h>
using namespace std;

char s[500002];

unordered_map<char, int> lst, cnt;

void solve(){
	lst.clear();
	cnt.clear();

	cin >> s;
	const int n = strlen(s);

	int u = 0;
	for (int i=0; i<n; ++i){
		if (cnt[s[i]] == 0) ++u;
		lst[s[i]] = i;
		++cnt[s[i]];
	}

	for (auto& [k, v] : cnt){
		v /= u;
		cout << k << ' ' << v << '\n';
	}

	int rem = u;
	for (int i=0; i<n; ++i){
		cout << s[i];
		if (--cnt[s[i]] == 0){
			--rem;
			if (rem == 0){
				cout << ' ';
				break;
			}
		}
	}

	cout << '\n';


}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
