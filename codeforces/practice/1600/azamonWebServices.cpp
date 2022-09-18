#include <bits/stdc++.h>
using namespace std;

// alternatively, can be solved in O(log(n)^2 * n^2)
// maintain a prefix of string hashes, and binary search for the first differing character to compare strs
// enumerate all swaps in "s", updating the string hash prefix of "s" using segment tree

void solve(){
    string s, c; cin >> s >> c;

    const int n = s.length();
    char mn = s.back();
    int mn_i = n-1;

    // instead of "n-1", "i" can actually start at the first position where "s" and "c" differ
    // however, the worst case remains the same, and starting at "n-1" removes an implementation step
    for (int i=n-1; i>=0; --i){
        if (s[i] < mn){
            mn = s[i];
            mn_i = i;
        } else {
            swap(s[i], s[mn_i]);
            if (s.compare(c) < 0){
                cout << s << '\n';
                return;
            }
            swap(s[mn_i], s[i]);
        }
    }

    cout << "---\n";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
