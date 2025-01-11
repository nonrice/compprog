#include <bits/stdc++.h>
using namespace	std;
#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long int

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif
	
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' ';	return out;};
	
	
int32_t	main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;


    int ret = 0;
    int last = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[last]) {
            ret += (i - last) * a[last];
            last = i;
        }
    }
    ret += (n - 1 - last) * a[last];

    cout << ret << endl;

	return 0;
}