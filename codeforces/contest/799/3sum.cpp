#include <bits/stdc++.h>
using namespace std;

int target[22][3] = {
    { 0, 0, 3 },
    { 0, 1, 2 },
    { 0, 4, 9 },
    { 0, 5, 8 },
    { 0, 6, 7 },
    { 1, 1, 1 },
    { 1, 3, 9 },
    { 1, 4, 8 },
    { 1, 5, 7 },
    { 1, 6, 6 },
    { 2, 2, 9 },
    { 2, 3, 8 },
    { 2, 4, 7 },
    { 2, 5, 6 },
    { 3, 3, 7 },
    { 3, 4, 6 },
    { 3, 5, 5 },
    { 4, 4, 5 },
    { 5, 9, 9 },
    { 6, 8, 9 },
    { 7, 7, 9 },
    { 7, 8, 8 } 
};

void solve(){
    int n; cin >> n;
    int d[10] = { 0 };
    while (n--){
        int v; cin >> v;
        v %= 10;
        ++d[v];
    }
    
    for (int i=0; i<22; ++i){
        int* tri = target[i];
        if (
            count(tri, tri+3, tri[0]) <= d[tri[0]] &&
            count(tri, tri+3, tri[1]) <= d[tri[1]] &&
            count(tri, tri+3, tri[2]) <= d[tri[2]] 
        ){
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main(){
    int cases; cin >> cases;
    while (cases--) solve();
}

