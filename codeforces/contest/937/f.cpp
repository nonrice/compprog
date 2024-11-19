#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a, b, c; cin >> a >> b >> c;

	if (a+1 != c){
		cout << "-1\n";
		return;
	}

	priority_queue<int, vector<int>, greater<>> l;
	if (a != 0){
		l.push(0);
		l.push(0);
		--a;
	} else if (b != 0){
		l.push(0);
		--b;
	} else {
		l.push(0);
		--c;
	}
	while (a>0){
		int t = l.top(); l.pop();
		l.push(t+1);
		l.push(t+1);
		--a;
	}
	while (b>0){
		int t = l.top(); l.pop();
		l.push(t+1);
		--b;
	}
	while (c>0){
		int t = l.top(); l.pop();
		l.push(t+1);
		--c;
	}
	int mx = 0;
	while (!l.empty()){
		mx = l.top();
		l.pop();
	}
	cout << mx << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		solve();
	}
}
