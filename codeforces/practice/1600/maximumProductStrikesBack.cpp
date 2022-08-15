#include <bits/stdc++.h>
using namespace std;

/* 
 * variables
 * twos before first neg
 * position of first neg
 * twos after last neg
 * position of last neg
 * if val is neg right now
 * if ive passed the first neg
 * best start and end
 * best product
 */

void solve(){
    int n; cin >> n;
    
    int bst = 0;
    int cur = 0;
    int i=0, bi=0, bj=0;
    int neg1=0, neg2=0;
    int neg1v=0, neg2v=0;
    bool is_neg=false, saw_neg=false;
    bool in_seg = false;
    for (int j=0; j<=n; ++j){
        int v;
        if (j < n) cin >> v;
        if (j == n || (v == 0 && in_seg)){
            int ci=i, cj=j;
            if (is_neg){
                if (neg1v < neg2v) ci = neg1+1; 
                else cj = neg2;
                cur -= min(neg1v, neg2v);
            }
            if (cur > bst){
                bst = cur;
                bi = ci;
                bj = cj;
            }
            cur = 0;
            in_seg = false;
            neg1 = neg2 = neg1v = neg2v = 0;
            is_neg = saw_neg = false;
        } else if (v != 0) {
            if (!in_seg){
                in_seg = true;
                i = j;
            }
            if (v < 0){
                is_neg ^= 1;
                neg2v = 0;
                neg2 = j;
                if (!saw_neg){
                    if (v == -2) ++neg1v;
                    saw_neg = true;
                    neg1 = j;
                }
            }
            if (abs(v) == 2){
                ++cur;
                if (!saw_neg) ++neg1v;
                ++neg2v;
            }
        }
    }
    
    cout << bi << ' ' << n-bj << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
