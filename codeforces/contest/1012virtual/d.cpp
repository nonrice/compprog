#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100000;

vector<int> p;
bool r[N+1];

void solve(){
    int n; cin >> n;
    int c = *lower_bound(p.begin(), p.end(), n/2);

    set<int> u;
    for (int i=0; i<n; ++i){
        u.insert(i+1);
    }
            
    int d = 0;
    for (int i=0; i<n; ++i){
        if (!u.count(c+d)){
            break;
        }

        cout << c+d << ' ';
        u.erase(c+d);
        if (d<=0){
            d *= -1;
            ++d;
        } else {
            d *= -1;
        }
    }

    while (!u.empty()){
        cout << *u.begin() << ' ';
        u.erase(u.begin());
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    
    for (int f=2; f<=N; ++f){
        for (int x=f+f; x<=N; x+=f){
            r[x] = true;
        }
    }
    for (int x=2; x<=N; ++x){
        if (r[x] == false){
            p.push_back(x);
        }
    }

    int t; cin >> t;
    while (t--){
        solve();
    }
}
