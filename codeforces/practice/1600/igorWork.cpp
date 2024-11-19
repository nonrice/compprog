#include <bits/stdc++.h>
using namespace std;

array<bitset<1000>, 1000> B;

bool check_h(int r, int c1, int c2){
    if (c1 > c2) swap(c1, c2);
    for (int c=c1; c<=c2; ++c){
        if (B[r][c]) return false;
    }
    return true;
}
    
bool check_v(int c, int r1, int r2){
    if (r1 > r2) swap(r1, r2);
    for (int r=r1; r<=r2; ++r){
        if (B[r][c]) return false;
    }
    return true;
}

int main(){
    int n, m; cin >> n >> m;
    
    int r1, c1, r2, c2;
    for (int r=0; r<n; ++r){
        string s; cin >> s;
        for (int c=0; c<m; ++c){
            if (s[c] == '*') B[r][c] = true; 
            else if (s[c] == 'S'){
                r1 = r;
                c1 = c;
            } else if (s[c] == 'T'){
                r2 = r;
                c2 = c;
            }
        }
    } 
    
    for (int c=0; c<m; ++c){
        if (check_v(c, r1, r2) && check_h(r1, c1, c) && check_h(r2, c2, c)){
            cout << "YES\n";
            return 0;
        }
    }

    for (int r=0; r<n; ++r){
        if (check_h(r, c1, c2) && check_v(c1, r1, r) && check_v(c2, r2, r)){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}
