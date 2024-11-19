#include <bits/stdc++.h>
using namespace std;

int arr[8][3] = {
	{ 0, 3, 6 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	{ 0, 1, 2 },
	{ 3, 4, 5 },
	{ 6, 7, 8 },
	{ 0, 4, 8 },
	{ 2, 4, 6 }
};

void solve(){
	string a, b, c; cin >> a >> b >> c;

	string s = a + b + c;

	for (int i=0; i<8; ++i){
		if (s[arr[i][0]] != '.' && s[arr[i][0]] == s[arr[i][1]] && s[arr[i][0]] == s[arr[i][2]]){
			cout << s[arr[i][0]] << '\n';
			return;
		}
	}

	cout << "DRAW\n";
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
