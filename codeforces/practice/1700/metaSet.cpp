#include <bits/stdc++.h>
using namespace std;

struct card {
    unsigned int val = 0;
    
    card(int feats){
        unsigned int pw = 1;
        for (int i=0; i<feats; ++i){
            int v; cin >> v;
            val += pw*v;
            pw *= 3;
        }
    }

    int operator[](int x){
        unsigned int tval = val;
        while (x--) tval /= 3;
        return tval%3;
    }
};

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vector<card> cards;
    for (int i=0; i<n; ++i) cards.emplace_back(k);

    map<unsigned int, int> mid;
    for (int i=0; i<n; ++i){
        for (int j=i+1; j<n; ++j){
            unsigned int comp = 0;
            unsigned int pw = 1;
            for (int h=0; h<k; ++h){
                int c1 = cards[i][h];
                int c2 = cards[j][h];
                if (c1 == c2){
                    comp += c1*pw;
                } else {
                    int t = 0;
                    for (; t==c1 || t==c2; ++t);
                    comp += t*pw;
                }
                pw *= 3;
            }
            ++mid[comp];
        }
    }
    
    int ans = 0;
    for (int i=0; i<n; ++i){
        int num = mid[cards[i].val];
        ans += num*(num-1)/2;
    }

    cout << ans << '\n';
}
