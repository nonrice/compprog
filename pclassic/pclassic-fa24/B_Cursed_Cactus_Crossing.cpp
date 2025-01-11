#include <bits/stdc++.h>
using namespace	std;
#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long int

	
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' ';	return out;};
	
	
int32_t	main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    cin >> a;
    sort(a.begin(), a.end());

    int ret = k * (k + 1) / 2;
    for (int m : a) {
        int x = 0;
        for (int s=k+2; s>=1; s/=2){
            while ((x+s)*(x+s+1)/2 <= m){
                x += s;
            }
        }
        /*
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid * (mid + 1) / 2 >)
        } */
        if (x*(x+1)/2 == m){
            ret = min(ret, (x - 1) * x / 2);
            break;
        }
        //binary search x * (x + 1) / 2 == m
        //if no equal then continue
    }
    cout << ret << endl;

	return 0;
}