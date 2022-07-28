#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<string> a(n);
    for (string& v : a) cin >> v;
    
    for (int i=n-2; i>=0; --i){
        if (a[i] > a[i+1]){
            int end = 0;
            while (a[i][end] == a[i+1][end]) ++end;
            a[i] = a[i].substr(0, end);
        }
    }

    for (string& v : a) cout << v << '\n';
}
