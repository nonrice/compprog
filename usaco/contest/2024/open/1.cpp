#include <bits/stdc++.h>
using namespace std;

string s, t;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n, k; cin >> n >> k;
	cin >> s >> t;
	int o = count(t.begin(), t.end(), '1');
	for (int i=0; i<n; ++i){
		if ((i < o && t[i] != '1') || (i >= 0 && t[i] != '0')){
			s[i] = (s[i]=='1') ? '0' : '1';
		}
	}

	for (int i=0; i<o; ++i){
		if (s[i] == '1'){
			continue;
		}

	}
}
