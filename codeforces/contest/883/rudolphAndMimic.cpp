#include <bits/stdc++.h>
using namespace std;

#define INTERACTIVE

map<int, int> f[5];
int a[200];
int stage = 0;
int rem;

void read(){
	for (int i=0; i<rem; ++i){
		cin >> a[i];
		++f[stage][a[i]];
	}
	++stage;
}

void del(int keep){
	vector<int> p;
	for (int i=0; i<rem; ++i){
		if (a[i] != keep){
			p.push_back(i+1);
			--f[stage-1][a[i]];
		}
	}
	rem -= p.size();
	cout << "- " << p.size();
	if (p.size() != 0) cout << ' ';
	for (int i=0; i<p.size(); ++i){
		cout << p[i];
		if (i != p.size()-1) cout << ' ';
	}
	cout << '\n';
	cout.flush();
}

void del_none(){
	cout << "- 0\n";
	cout.flush();
}

int get_impostor(){
	for (auto [k, v] : f[stage-1]){
		if (f[stage-1][k] > f[stage-2][k]){
			return k;
		}
	}
	return -1;
}

void solve(){
	stage = 0;
	cin >> rem;
	for (int i=0; i<5; ++i) f[i].clear();

	read();
	del_none();
	read();
	int imp = get_impostor();
	if (imp != -1){
		goto stage2;
	}
	del_none();
	read();
	imp = get_impostor();

stage2:
	del(imp);
	read();
	imp = get_impostor();
	if (imp != -1){
		goto stage3;
	}
	del_none();
	read();
	imp = get_impostor();

stage3:
	for (int i=0; i<rem; ++i){
		if (a[i] == imp){
			cout << "! " << i+1 << '\n';
			cout.flush();
			return;
		}
	}
	cout << "! " << 1 << '\n';
	cout.flush();
}

int main(){
	int t; cin >> t;
	while (t--) solve();
}
