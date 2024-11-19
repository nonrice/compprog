#include <bits/stdc++.h>
using namespace std;

int main(){
    int l; cin >> l;

    long long ans = 0;
    long long mul = 1;
    bool bad = false;
    int lst_good = 0;
    stack<short> fs;
    while (l--){
        string tok; cin >> tok;
        //cout << lst_good << '\n';
        if (tok == "add") {
            if (bad || ans+mul > UINT_MAX){
                cout << "OVERFLOW!!!\n";
                return 0;
            }
            ans += mul;
        } else if (tok == "for") {
            short n; cin >> n;
            if (!bad){
                if ((bad = (mul*n)+ans > UINT_MAX)) lst_good=fs.size();
                else mul *= n;
            }
            fs.push(n);
        } else if (tok == "end") {
            if (!bad) mul /= fs.top();
            fs.pop();
            if (bad && (int)fs.size()==lst_good) bad = false;
        }
    }

    cout << ans << '\n';
}

