#include <bits/stdc++.h>
using namespace std;

int p[750][750];
string s;
bool adj[750][750];

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i=0; i<n-1; ++i){
		cin >> s;
		for (int j=i+1; j<n; ++j){
			p[i][j] = s[j-i-1]-'0';
		}
	}
	
	int ans = 0;
	for (int d=1; d<n; ++d){
		for (int i=0; i+d<n; ++i){
			int j = i+d;
			int s = 0;
			for (int k=i+1; k<j; ++k){
				s += p[i][k]*adj[k][j];
			}
			if (s%2 != p[i][j]){
				adj[i][j] = true;
				++ans;
			}
		}
	}

	cout << ans << '\n';
}
