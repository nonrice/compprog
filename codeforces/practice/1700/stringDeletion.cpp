#include <bits/stdc++.h>
using namespace std;

// idea:
// maintain 2 pointers: bgn, del
// bgn represents the beginning of the string
// del represents the character to delete
//
// we will simulate the operations:
// 1. Increment del until s[del] == s[del+1] and del>bgn. This ensures deleting s[del] will not merge 2 segments, and shorten the process.
// 2. Delete s[del]. If no valid s[del] is found in step 1, just delete s[bgn] (any character can be deleted, we use s[bgn] just for simplicity).
// 3. Increment bgn to new bgn' such that s[bgn] != s[bgn'] to simulate the deletion of the prefix.

char s[200001];
int nxt[200001], prv[200001];

void solve(){
    int n; cin >> n;
    cin >> s;

    iota(nxt, nxt+n+1, 1);
    iota(prv, prv+n+1, -1);

    int ans = 0;
    int bgn=0, del=0;
    while (bgn != n){
        while (nxt[del] != n && s[nxt[del]] != s[del]) del = nxt[del];

        if (nxt[del] == n){
            bgn = nxt[bgn];
        } else if (del != bgn) {
            nxt[prv[del]] = nxt[del];
            prv[nxt[del]] = prv[del];
            del = nxt[del];
        } 

        char cur = s[bgn];
        while (bgn != n && s[bgn] == cur) bgn = nxt[bgn];
        del = max(del, bgn);

        ++ans;
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
