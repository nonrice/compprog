#include <bits/stdc++.h>
using namespace std;

pair<int, int> d[4] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1} };

int n, m;
string g[1000000];

bool check(int r, int c){
	bool e = false;
	for (auto [dr, dc] : d){
		if (r+dr<n && r+dr>=0 && c+dc<m && c+dc>=0 && g[r+dr][c+dc]=='.'){
			if (e){
				return false;
			}
			e = true;
		}
	}
	return true;
}

void solve(){
	cin >> n >> m;
	int sr=-1, sc=-1;
	for (int r=0; r<n; ++r){
		cin >> g[r];
		int c = g[r].find('L');
		if (c != string::npos){
			sr = r;
			sc = c;
		}
	}

	queue<pair<int, int>> q({ { sr, sc } });
	while (!q.empty()){
		auto [r, c] = q.front();
		q.pop();
		for (auto [dr, dc] : d){
			if (r+dr<n && r+dr>=0 && c+dc<m && c+dc>=0 && g[r+dr][c+dc]=='.' && check(r+dr, c+dc)){
				g[r+dr][c+dc] = '+';
				q.emplace(r+dr, c+dc);
			}
		}
	}

	for (int r=0; r<n; ++r){
		cout << g[r] << '\n';
	}
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
