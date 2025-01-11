#include <bits/stdc++.h>
using namespace std;

struct st_node {
    st_node* l_ch = nullptr;
    st_node* r_ch = nullptr;
    int l_s, r_s;
    long long x = 0;
    
    st_node(int l, int r) : l_s(l), r_s(r) {
        if (l != r){
            int m = (l+r)/2;
            l_ch = new st_node(l, m);
            r_ch = new st_node(m+1, r);
        }
    }
 
    void set(int i, long long y){
        if (l_s == r_s){
            x = y;
            return;
        }
        if (i <= (l_s+r_s)/2){
            l_ch->set(i, y);
        } else {
            r_ch->set(i, y);
        }
        x = l_ch->x + r_ch->x;
    }
 
    long long query(int l, int r){
        if (l <= l_s && r >= r_s){
            return x;
        }
        int m = (l_s+r_s)/2;
        if (l <= m && r >= m+1){
            return l_ch->query(l, r) + r_ch->query(l, r);
        }
        if (r < m+1){
            return l_ch->query(l, r);
        }
        if (l > m){
            return r_ch->query(l, r);
        }
        cerr << "bad query" << l << ' ' << r << '\n';
    }
};