#include <bits/stdc++.h>
using namespace std;

int s[100000], e[100000];
map<int, queue<int>> a;

multiset<int> car;
int p = 1;
long long d = 0;
int n, m, k;

int closest_stop_in_car(){
	auto it = car.lower_bound(p);
	if (it != car.end()) return *it;
	it = car.begin();
	if (it == car.end()) return -1;
	else return *it;
}

int closest_nonempty_stop(){
	auto it = a.lower_bound(p);
	if (it != a.end()) return it->first;
	it = a.begin();
	if (it == a.end()) return -1;
	else return it->first; 
}

long long dist(int l, int r){
	return r-l + ((r-l<0) ? m : 0);
}

bool next_stop(){
	while (car.size() < k && !a[p].empty()){
		car.insert(a[p].front());
		a[p].pop();
	}
	if (a[p].empty()) a.erase(p);

	int dest = closest_stop_in_car();
	int mid_dest = closest_nonempty_stop();
	//cout << p << ' ' << car.size() << ' ' << dest << ' '<< mid_dest << '\n';

	if (mid_dest == -1 && dest == -1){
		return false;
	}

	if (mid_dest != dest && (dest == -1 || (mid_dest != -1 && dist(p, mid_dest)<dist(p, dest) && car.size() < k))){
		d += dist(p, mid_dest);
		p = mid_dest;
		next_stop();
	} else {
		d += dist(p, dest);
		p = dest;
		car.erase(dest);
	}
	
	return true;
}

void solve(){
	a.clear();
	car.clear();
	d = 0, p = 1;

	cin >> n >> m >> k;
	for (int i=0; i<n; ++i) cin >> s[i];
	for (int i=0; i<n; ++i) cin >> e[i];
	for (int i=0; i<n; ++i) a[s[i]].push(e[i]);

	while (next_stop());

	cout << d << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
