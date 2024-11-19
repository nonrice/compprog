#include <bits/stdc++.h>
using namespace std;

struct seg {
	int l, r, k, i;
}
int ans[200000];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	vector<seg> s(n);
	for (int i=0; i<n; ++i){
		s[i].i = i;
		cin >> s[i].l >> s[i].r >> s[i].k;
	}

	// intersection 1
	{
		sort(s.begin(), s.end(), [&](const seg& a, const seg& b){
			return a.l+a.k < b.l+b.k;
		});
		set<seg>
		for ()
	}
}
