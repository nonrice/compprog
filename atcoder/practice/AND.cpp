#include <bits/stdc++.h>
using namespace std;

constexpr int D = 0x3FFFFFFF; // 30 1s

struct st_node {
	st_node* l_ch = nullptr;
	st_node* r_ch = nullptr;
	int l_s, r_s;
	int x = D;
	
	st_node(int l, int r) : l_s(l), r_s(r) {
		if (l != r){
			int m = (l+r)/2;
			l_ch = new st_node(l, m);
			r_ch = new st_node(m+1, r);
		}
	}

	void set(int i, int y){
		if (l_s == r_s){
			x = y;
			return;
		}
		if (i <= (l_s+r_s)/2){
			l_ch->set(i, y);
		} else {
			r_ch->set(i, y);
		}
		x = l_ch->x & r_ch->x;
	}

	int query(int l, int r){
		if (l<=l_s && r>=r_s){
			return x;
		}
		int m = (l_s+r_s)/2;
		return (l<=m ? l_ch->query(l, r) : D) & (r>m ? r_ch->query(l, r) : D);
	}

	~st_node(){
		if (l_s == r_s){
			return;
		}
		delete l_ch;
		delete r_ch;
	}
};

int p[200001];
vector<pair<int, int>> s;

void solve(){
	int l, r; cin >> l >> r;
	--l, --r;
	if (p[r+1]-p[l] != 0){
		cout << r-l+1 - (p[r+1]-p[l]) << '\n';
		return;
	}
	for (int i=0; i<s.size(); ++i){
		if (s[i].first >= l && s[i].second <= r){
			cout << s[i].second-s[i].first+r-l << '\n';
			return;
		}
	}
	cout << "-1\n";
	return;
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	st_node st(0, n-1);
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		p[i+1] = p[i];
		if (x == 0){
			++p[i+1];
		}
		st.set(i, x);
	}

	for (int i=0; i<n; ++i){
		if (st.query(0, i) != 0){
			continue;
		}
		int l = 0;
		for (int step=i; step>=1; step/=2){
			while (step+l<=i && st.query(step+l, i) == 0){
				l += step;
			}
		}
		s.emplace_back(l, i);
	}
	sort(s.begin(), s.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
		return a.second-a.first < b.second-b.first;
	});

	int q; cin >> q;
	while (q--){
		solve();
	}
}
