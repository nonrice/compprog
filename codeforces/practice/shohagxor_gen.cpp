#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r){
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    cout << "100\n";
    for (int i=10; i<=109; ++i){
        cout << i/10 << ' ' << i%10 + 1 << '\n';
    }
}