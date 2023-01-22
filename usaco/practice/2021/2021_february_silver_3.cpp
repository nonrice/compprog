#include <bits/stdc++.h>
using namespace std;

int a[500][500];
int p[501][501];
int n;

long long cnt_rect(int mn){
    for (int j=0; j<n; ++j){
        for (int i=1; i<=n; ++i) p[i][j] = p[i-1][j] + (a[i-1][j]<mn);
    }

    long long cnt = 0;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            if (a[i][j]>=mn){
                int r=i, c=j;
                while (r+1<n && a[r+1][c]>=mn) ++r;
                do {
                    cnt += r-i+1;
                    while (p[r+1][c+1]!=p[i][c+1] && r>i) --r;
                    ++c;
                } while (c<n && p[r+1][c]==p[i][c]);
            }
        }
    }

    return cnt;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j) cin >> a[i][j];
    }

    cout << cnt_rect(100) - cnt_rect(101) << '\n';
}
