#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

long long binpow(long long a, long long b, long long m){
    long long ans = 1;
    while (b){
        if (b&1) ans = ans*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return ans;
}

struct polyhash {
    long long m, b;
    vector<long long> p;
    
    polyhash(const string& s, long long m, long long b) : m(m), b(b) {
        p = vector<long long>(s.size()+1);
        long long bp = 1;
        for (size_t i=1; i<=s.size(); ++i){
            p[i] = (p[i-1] + (s[i-1]-'a') * bp % m) % m;
            bp = bp*b % m;
        }
        // debug(p);
    }
 
    long long substr(int l, int r){
        debug(l, r);
        return ((p[r] - p[l] + m) % m) * binpow(binpow(b, l, m), m-2, m) % m;
    }
};

constexpr long long M = 999998423;
constexpr long long B = 29;

void solve(){
    int n, q; cin >> n >> q;

    string s; cin >> s;

    string t(s.rbegin(), s.rend());
    polyhash h(s, M, B), g(t, M, B);

    vector<vector<int>> p(26, vector<int>(n+1)), po(26, vector<int>(n+1)), pe(26, vector<int>(n+1));

    for (int i=0; i<n; ++i){
        ++p[s[i]-'a'][i+1];
        if (i % 2){
            ++pe[s[i]-'a'][i+1];
        } else {
            ++po[s[i]-'a'][i+1];
        }

        for (int j=0; j<26; ++j){
            p[j][i+1] += p[j][i];
            pe[j][i+1] += pe[j][i];
            po[j][i+1] += po[j][i];
        }
    }

    while (q--){
        int l, r; cin >> l >> r;
        const long long w = r-l+1;
        --l;

        bool f = false;

        for (int c=0; c<26; ++c){
            if (p[c][r]-p[c][l] == w){
                f = true;
                cout << "0\n";
                break;
            }
        }
        if (f){
            continue;
        }

        for (int c1=0; c1<26; ++c1){
            for (int c2=0; c2<26; ++c2){
                if (po[c1][r]-po[c1][l] + pe[c2][r]-pe[c2][l] == w){
                    f = true;
                    cout << (2+w - w%2)*(w/2)/2 << '\n';
                    break;
                }
            }
            if (f){
                break;
            }
        }
        if (f){
            continue;
        }


        long long ans = (2+w)*(w-1)/2;
        if (h.substr(l, r) == g.substr(n-1 - (r-1), n - l)){
            ans -= w;
            debug(ans);
        }

        cout << ans << '\n';
        
    }



}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--){
        solve();
    }
}