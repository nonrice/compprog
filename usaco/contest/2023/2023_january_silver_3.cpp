#include <bits/stdc++.h>
using namespace std;

int a[100001];
bool ans[1000001];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int k=0;
    int minctz = INT_MAX;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        k += a[i];
        minctz = min(minctz, __builtin_ctz(a[i]));
    }

    for (int i=0; i<n; ++i) a[i]/=(1<<minctz);

    bool dir = false;
    int cur = 0;
    for (int i=0; i<k/(1<<minctz); ++i){
tryagain:
        if (cur-dir>=0 && a[cur-dir]){
            --a[cur-dir];

            if (dir) --cur;
            else ++cur;

            ans[i] = dir;
        } else {
            dir ^= 1;
            assert((cur-dir>=0 && a[cur-dir]));
            goto tryagain;
        }
    }

    for (int i=0; i<k/(1<<minctz); ++i) ans[(k/(1<<(minctz-1)))-i-1] = !ans[i];

    for (int i=0; i<k/(1<<(minctz-1)); ++i){
        for (int j=k/(1<<(minctz-1)); j<k; j+=(k/(1<<(minctz-1)))){
            ans[i+j] = ans[i];
        }
    }

    for (int i=0; i<k; ++i){
        if (ans[i]) cout << 'L';
        else cout << 'R';
    }


}
