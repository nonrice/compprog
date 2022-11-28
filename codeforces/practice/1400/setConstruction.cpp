#include <bits/stdc++.h>
using namespace std;

char ans[1000][1001];
int buf[1000];

void solve(){
    int n; cin >> n;
    for (int i=0; i<n; ++i){
        cin >> ans[i];
        ans[i][i] = '1';
    }

    for (int i=0; i<n; ++i){
        int p=0;
        for (int j=0; j<n; ++j){
            if (ans[j][i] == '1') buf[p++] = j+1; 
        }
        cout << p << ' ';
        for (int i=0; i<p; ++i) cout << buf[i] << ' ';
        cout << '\n';
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
