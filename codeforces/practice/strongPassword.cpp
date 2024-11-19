#include <bits/stdc++.h>
using namespace std;

void solve(){
	queue<int> p[10];
	string s; cin >> s;
	int n = s.size();
	int m; cin >> m;
	string l, r; cin >> l >> r;

	for (int i=0; i<n; ++i){
		p[s[i]-'0'].push(i);
	}

	int lst = -1;
	for (int i=0; i<m; ++i){
		int nxt = -1;
		int nxt_no;
		for (int j=l[i]-'0'; j<=r[i]-'0'; ++j){
			while (!p[j].empty() && p[j].front() < lst){
				p[j].pop();
			}
			if (p[j].empty()){
				cout << "YES\n";
				return;
			}
			if (p[j].front() > nxt){
				nxt = p[j].front();
				nxt_no = j;
			}
		}
		lst = p[nxt_no].front();
		p[nxt_no].pop();
	}

	cout << "NO\n";
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
