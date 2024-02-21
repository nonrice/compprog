// appending c[i] causes update of d[l+1] to min(d[l+1], c[i]) for the last d[l]<c[i]
// therefore c[i] has no effect only if d[l+1] = c[i] since d[l+1] is implied to be more than c[i]
// aka if c[i] exists inside d
// We want to use as many b[i] as possible in this manner
//
// Approach
// Construct c from left to right
// If at least one b[i] can be used in that manner, use it. Otherwise use the larger: largest element remaining in b or the next element of a
// Once the elements of a run out, append the remaining b[i] in reverse order. 

#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	queue<int> a;
	multiset<int, greater<int>> ob, o2;
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		a.push(x);
	}
	for (int i=0; i<m; ++i){
		int x; cin >> x ;
		ob.insert(x);
	}

	vector<int> d(n+1, INT_MAX);
	vector<int> ans;
	d[0] = INT_MIN;
	for (int i = 0; i < n+m; i++) {
		if (o2.empty() && !a.empty()){
			int nxt;
			if (ob.empty() || a.front() > *ob.begin()){
				nxt = a.front(); 
				a.pop();
			} else {
				nxt = *ob.begin();
				ob.erase(ob.begin());
			}
			ans.push_back(nxt);
			int l = upper_bound(d.begin(), d.end(), nxt) - d.begin();
			if (d[l-1] < nxt && nxt < d[l]){
				if (o2.find(d[l]) != o2.end()) o2.erase(o2.find(d[l]));
				d[l] = nxt;
				if (ob.find(d[l]) != ob.end()){
					o2.insert(d[l]);
				}
			}
		} else if (!o2.empty()) {
			ans.push_back(*o2.begin());
			ob.erase(ob.find(*o2.begin()));
			if (ob.find(*o2.begin()) == ob.end()){
				o2.erase(o2.begin());
			}
		} else {
			ans.push_back(*ob.begin());
			ob.erase(ob.begin());
		}
    }

	for (auto v : ans) cout << v << ' ';
	cout << '\n';
}

int main(){
	cin.tie(0)->ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) solve();
}
