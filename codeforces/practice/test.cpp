#include <bits/stdc++.h>
using namespace std;

constexpr int n = 5;
int q = 5;

bitset<n> b;

int main(){
	mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());

	// Initialize the bitset
	for (int i=0; i<n; ++i){
		b[i] = mt()%2;
	}

	while (q--){
		// Choose the query type
		int type = mt()%2;

		if (type){
			// Point update
			int i = mt()%n;
			int value = mt()%2;
			b[i] = value;
		} else {
			// Range query
			int l = mt()%n, r = mt()%n;
			if (l > r){
				swap(l, r);
			}
			cout << ((b>>(l))<<(l+n-1-r)).count() << '\n';
		}
	}
}
