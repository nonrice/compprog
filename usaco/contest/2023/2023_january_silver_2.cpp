#include <bits/stdc++.h>
using namespace std;

// for each cell in initial config, calculate:
// -The number of cows that end up travelling to that cell c[i][j]
//
// First calculate initial amount of money
// If you flip cell a[i][j]
// c[i][j] cows will go from d[i][j]
// to d[i+1][j]/d[i][j+1]
//  
// now you can propogate this in O(n) time

int h[1501][1501];
int c[1501][1501];
bool a[1501][1501];

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n; cin >> n;

    // input signs into a and costs into c
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            h[i][j] = 1;

            char ch; cin >> ch;
            a[i][j] = ch=='R';
        }
        cin >> c[i][n];
    }
    for (int i=0; i<n; ++i) cin >> c[n][i];

    // calculate initial h
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            if (j>0 && a[i][j-1]) h[i][j] += h[i][j-1];
            if (i>0 && !a[i-1][j]) h[i][j] += h[i-1][j];
        }
    }

    //calculate initial cost
    int cur = 0;
    for (int i=0; i<n; ++i){
        if (a[i][n-1]) cur += h[i][n-1]*c[i][n];
        if (!a[n-1][i]) cur += h[n-1][i]*c[n][i];
    }
    cout << cur << '\n';
    
    //queries time
    int q; cin >> q;
    while (q--){
        int y, x; cin >> y >> x; --y, --x;
        
        //remove cows from the previous path
        int i=y, j=x;
        if (a[y][x]) ++j;
        else ++i;
        while (i<n && j<n){
            h[i][j] -= h[y][x];
            if (a[i][j]) ++j;
            else ++i;
        }
        cur -= h[y][x]*c[i][j];

        //add cows to new path
        i=y, j=x;
        a[y][x] ^= 1;
        if (a[y][x]) ++j;
        else ++i;
        while (i<n && j<n){
            h[i][j] += h[y][x];
            if (a[i][j]) ++j;
            else ++i;
        }
        cur += h[y][x]*c[i][j];
    /*
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j) cout << a[i][j] << ' ';
            cout << '\n';
        }
        cout << "--\n";
        for (int i=0; i<=n; ++i){
            for (int j=0; j<=n; ++j) cout << c[i][j] << ' ';
            cout << '\n';
        }
        cout << "--\n";
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j) cout << h[i][j] << ' ';
            cout << '\n';
        }
        cout << "--\n";

        */
        cout << cur << '\n';
    }
}
