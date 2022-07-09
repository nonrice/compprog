#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int total = a+b+c+d;

    if (total==0){
        cout << "0\n";
    } else if (total<=3){
        cout << "1\n";
    } else {
        cout << "2\n";
    }
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}
