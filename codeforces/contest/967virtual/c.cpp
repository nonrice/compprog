#define INTERACTIVE

#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b){
	cout << "? " << a << ' ' << b << endl;
	int x; cin >> x;
	return x;
}

void solve(){
	int n; cin >> n;

	set<pair<int, int>> e;
	set<int> vis({1});
	function<void(int, int)> s = [&](int a, int b)->void{
		int x = ask(a, b);
		vis.insert(x);
		if (x == a){
			e.emplace(a, b);
			return;
		}
		s(x, b);
		if (!vis.count(x)){
			s(a, x);
		}
	};

	for (int i=2; i<=n; ++i){
		vis.insert(i);
		s(1, i);
	}

	cout << "! ";
	for (auto [u, v] : e){
		cout << u << ' ' << v << ' ';
	}
	cout << endl;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
