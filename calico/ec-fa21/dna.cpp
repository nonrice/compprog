#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    
    while (n--){
        string s; cin >> s;
        for (char ch : s){
            if (ch == 'A') cout << 'T';
            else if (ch == 'T') cout << 'A';
            else if (ch == 'C') cout << 'G';
            else if (ch == 'G') cout << 'C';
        }
        cout << '\n';
    }
}
