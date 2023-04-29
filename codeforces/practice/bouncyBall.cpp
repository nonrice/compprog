#include <bits/stdc++.h>
using namespace std;

void solve(){
	int h, w, a, b, c, d; cin >> h >> w >> a >> b >> c >> d;
	//cout << h << ' '<< w << ' '<< a << ' ' << b << ' ' << c << ' ' << d << '\n';
	cin.ignore(1);
	int v=1, r=1;
	if (getchar() == 'U') v=-1;
	if (getchar() == 'L') r=-1;
	cin.ignore(1);

	int steps = lcm(h-1, w-1);
	if ((steps/(h-1) % 2) || (steps/(w-1) % 2)) steps *= 2;

	int ans = 0;
	while (steps--){
		if (a == c && b == d){
			cout << ans << '\n';
			return;
		}

		bool bounce = false;
		if (a+v<1 || a+v>h){
			v *= -1;
			bounce = true;
		}
		if (b+r<1 || b+r>w){
			r *= -1;
			bounce = true;
		}

		ans += bounce;
		a += v;
		b += r;
	}

	cout << "-1\n";
}

int main(){
	//cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
