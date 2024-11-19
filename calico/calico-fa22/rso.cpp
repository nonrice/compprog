#include <bits/stdc++.h>
using namespace std;

void solve(){
    int yr; cin >> yr;
    cin.ignore();
    string s; getline(cin, s);
    
    string w;
    if (s.find(" ") == string::npos) w = s;
    else w = s.substr(0, s.find(" "));


    if (s.size() > 50){
        cout << "INVALID\n";
        return;
    }

    if (yr < 2010) {
        cout << "VALID\n";
        return;
    } else {
        for (char& ch : w) ch = tolower(ch);
        if (w=="california" || w == "cal" || w=="berkeley") cout << "INVALID\n";
        else cout << "VALID\n";
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int cases; cin >> cases;
    while (cases--) solve();
}
