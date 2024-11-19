#include <bits/stdc++.h>
using namespace std;

// Restriction for S:
// s[i] = (l+k)*prod(f[0:i])
// The multiplication of a prefix of f ensures each number is a factor or multiple of each other number, by definition
//
// It's easy to prove that f must consist of only 2s, and at most one 3
//
// This makes calculating the number of possible fs very easy through some ad hoc math

void solve(){
	int l, r; cin >> l >> r;

	int len = 1;
	int pw = 1;
	while (l*pw*2 <= r){
		pw *= 2;
		++len;
	}

	int ways = 1 + (r-l*pw)/pw;
	if (pw>1 && l*pw/2*3 <= r){
		pw = pw/2*3;
		ways += (len-1)*(1 + (r-l*pw)/pw);
	}
	cout << len << ' ' << ways << '\n';

}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
