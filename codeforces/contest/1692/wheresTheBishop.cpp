#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<string> b(8);
    for (int i=0; i<8; ++i){
        cin >> b[i];
    }
    
    for (int r=1; r<7; ++r){
        for (int c=1; c<7; ++c){
            if (b[r][c]=='#' && b[r-1][c-1]=='#' && b[r-1][c+1]=='#' && b[r+1][c+1]=='#' && b[r+1][c-1]=='#'){
                cout << r+1 << ' ' << c+1 << '\n';
                return;
            }
        }
    }
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
