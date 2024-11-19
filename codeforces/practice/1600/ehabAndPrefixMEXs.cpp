#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    vector<bool> c(n+1);
    for (int& v : a){
        cin >> v;
        c[v] = true;
    }

    vector<int> b(n, -1);
    for (int i=1; i<n; ++i){
        if (a[i] != a[i-1]) b[i] = a[i-1];
    }
    
    int p=0;
    for (int& v : b){
        if (v == -1){
            while (c[p]) ++p;
            c[p] = 1;
            v = p;
        }

        cout << v << ' ';
    }
    
    cout << '\n';
}
