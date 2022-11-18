#include <bits/stdc++.h>
using namespace std;

constexpr int n = 100;

int main(){
    for (int i=2; i<=n; ++i){
        map<int, int> f;
        for (int d=2; d<=i; ++d){
            f[i/d]++;
        }

        //cout << i << "-> ";
        //for (auto [k, v] : f) cout << k << ": " << v << " | ";

        for (int d=2; d*d<=i; ++d){
            assert(f[i/d] == 1);
            //cout << f[d] << "=?" << (i/d - i/(d+1)) << ' ';
            assert(f[d] == i/d - i/(d+1));
        }
        
        //cout << f[1] << "=?" << (i+1)/2 << ' ';
        assert(f[1] == (i+1)/2);
    }
}
