#include <bits/stdc++.h>
using namespace std;

#define int long long

struct loc {
	long long t, x, y;

	bool operator<(const loc& o) const {
		return t < o.t;
	}

	long long sqdist(const loc& o){
		int dx = (x-o.x);
		int dy = (y-o.y);
		return dx*dx + dy*dy;
	}
};

loc a[100000];

signed main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int g, n; cin >> g >> n; 
	for (int i=0; i<g; ++i){
		cin >> a[i].x >> a[i].y >> a[i].t;
	}

	sort(a, a+g);
	int ans = 0;

	for (int i=0; i<n; ++i){
		long long x, y, t; cin >> x >> y >> t;
		loc m = {t, x, y};
		int ri = upper_bound(a, a+g, m) - a;
		int li = ri-1;

		loc r = m;
		loc l = m;
		if (ri != g) r = a[ri];
		if (li != -1) l = a[li];
		
		long long dtrm = r.t-m.t;
		long long dtml = m.t-l.t;
		//cout << r.sqdist(m) << ' ' << dtrm*dtrm << ' ' << l.sqdist(m) << ' '<< dtml*dtml << '\n';
		if (r.sqdist(m) > dtrm*dtrm || l.sqdist(m) > dtml*dtml) ++ans; 
	}

	cout << ans << '\n';
}
