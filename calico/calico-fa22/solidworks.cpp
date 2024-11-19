#include <bits/stdc++.h>
using namespace std;

char a[1505][1505];
char b[3009][3009];

void solve(){
    int h, w, d; cin >> h >> w >> d;
    cin.ignore();
    for (int r=0; r<h; ++r) memset(a[r], 0, w);
    for (int r=0; r<h+d+1; ++r) memset(b[r], 0, w+d+1);

    for (int i=0; i<h; ++i) cin.getline(a[i], 123123123123123);

    for (int i=0; i<h; ++i) memcpy(b[i], a[i], w);
    
    for (int r=0; r<h; ++r){
        for (int c=0; c<w; ++c){
            if (a[r][c] == '+'){
                for (int x=1; x<=d; ++x){
                    if (b[r+x][c+x] == '\\') break;
                    b[r+x][c+x] = '\\';
                }
            }
        }
    }

    for (int r=0; r<h; ++r){
        for (int c=0; c<w; ++c){
            if (a[r][c] == '\\' || a[r][c] == '|' || a[r][c] == '-' || a[r][c] == '+'){
                b[r+d+1][c+d+1] = a[r][c];
            }
        }
    }

    for (int r=0; r<h+d+1; ++r){
        for (int c=0; c<w+d+1; ++c){
            if (b[r][c] == 0) putchar_unlocked(' ');
            else putchar_unlocked(b[r][c]);
        }
        putchar_unlocked('\n');
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
