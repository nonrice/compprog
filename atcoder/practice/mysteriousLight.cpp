#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);

	long long n, x; cin >> n >> x;

	long long ans = n;
	long long a = n-x, b = x;
	while (b != 0){
		ans += (2*b) * (a/b);
		a = a%b;
		swap(a, b);
	}
	ans -= a;

	cout << ans << '\n';
}
