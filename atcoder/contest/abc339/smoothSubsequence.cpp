#include <bits/stdc++.h>
using namespace std;

// THANKYOUUSACOGUIDE
template <class T> class MaxSegmentTree {
  private:
	const T DEFAULT = 0;

	vector<T> segtree;
	int len;

  public:
	MaxSegmentTree(int len) : len(len) {
		segtree = vector<T>(len * 2, DEFAULT); 
	}

	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = max(segtree[ind], segtree[ind ^ 1]);
		}
	}

	T range_max(int start, int end) {
		T sum = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { sum = max(sum, segtree[start++]); }
			if (end % 2 == 1) { sum = max(sum, segtree[--end]); }
		}
		return sum;
	}
};

int main() {
	cin.tie(0)->ios_base::sync_with_stdio(false);

	MaxSegmentTree<int> dp(500010);
	int n, d; cin >> n >> d;
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		dp.set(x, dp.range_max(max(0, x-d), min(x+d, 500003)+1)+1);
	}

	cout << dp.range_max(0, 500002) << '\n';
}
