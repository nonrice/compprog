#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

#define INTERACTIVE

bool ask(string s){
    cout << "? " << s << endl;
    int x; cin >> x;
    if (x == -1){
        exit(0);
    }
    return x == 1;
}

void resp(string s){
    cout << "! " << s << endl;
}

string join(list<char>& v){
    string s(v.size(), ' ');
    auto it = v.begin();
    for (int i=0; i<v.size(); ++i){
        s[i] = *it;
        ++it;
    }
    return s;
}

void solve(){
    int n; cin >> n;

    if (n == 1){
        if (ask("1")){
            resp("1");
        } else {
            resp("0");
        }
        return;
    }

    list<char> s({'1'});
    while (s.size() < n){
        s.push_back('1');
        if (ask(join(s))){
            continue;
        }
        s.pop_back();
        s.push_back('0');
        if (ask(join(s))){
            continue;
        }
        s.pop_back();

        break;
    }
    while (s.size() < n){
        s.push_front('1');
        if (ask(join(s))){
            continue;
        }
        s.pop_front();
        s.push_front('0');
        if (ask(join(s))){
            continue;
        }
        s.pop_front();

        break;
    }

    if (s.size() == n){
        resp(join(s));
    } else {
        resp(string(n, '0'));
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;

    while (t--){
        solve();
    }
}