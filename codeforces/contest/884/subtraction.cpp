#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin>> t;
	while (t--){
		int a, b; cin >> a >> b;

		cout << (min(a, b)-1 + a + b) << '\n';
	}
}
