// https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>
using namespace std;

// // Binary Indexed Tree
// // BIT: Construct binary indexed tree for array of size n in O(n).
// // sum 1: Compute sum on range [1, r] in O(log(r)).
// // sum 2: Compute sum from on range [l, r] in O(log(r)).
// // inc: Increment element i of the array by d in O(log(i)).

// struct BIT {
//     vector<long long> s;
//     int n;

//     BIT(int n) : n(n) {
//         s.resize(n+1);
//     }

//     long long sum(int r){
//         long long ans = 0;
//         while (r >= 0){
//             ans += s[r];
//             r = (r & (r+1)) - 1;
//         }
//         return ans;
//     }

//     long long sum(int l, int r){
//         return sum(r) - sum(l-1);
//     }

//     void inc(int i, int d){
//         while (i < n){
//             s[i] += d;
//             i |= i+1;
//         }
//     }
// };


template <typename T>
struct BIT {
	vector<T> s;
	int n;

	// construct empty tree for array of size n
	BIT(int n) : n(n) {
		s.resize(n+1);
	}

	// compute sum on range [0, r)
	T query(int r){
		T ans = 0;
		while (r >= 0){
			ans += s[r];
			r = (r & (r+1)) - 1;
		}
		return ans;
	}
	
	// compute sum on range [l, r)
	T query(int l, int r){
		return query(r) - query(l);
	}

	// increment index i by d
	void inc(int i, T d){
		i += 1;
		while (i <= n){
			s[i] += d;
			i |= i+1;
		}
	}
};

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
{
    int n, q; cin >> n >> q;
    BIT<long long> t(n);
    for (int i=0; i<n; ++i){
        int x; cin >> x;
        t.inc(i, x);
    }

    while (q--){
        int c; cin >> c;
        if (c == 1){
            int i, v; cin >> i >> v;
            --i;
            t.inc(i, -t.query(i, i+1));
            t.inc(i, v);
        } else {
            int l, r; cin >> l >> r;
            --l;
            cout << t.query(l, r) << '\n';
        }
    }
}
}

