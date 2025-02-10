#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <dbg.hpp>
#else
#define debug(...)
#define debugArr(...)
#endif

long long dist(long long a, long long b){
    long long s = a*a + b*b;

    long long c = 0;
    for (long long h=s; h>=1; h/=2){
        while ((c+h)*(c+h) <= s){
            c+=h;
        }
    }

    return c;
}

struct seg {
    int al, ar, bl, br;

    bool operator<(const seg& o) const {
        return ar < o.ar;
    }

    seg(int al, int ar, int bl, int br) : al(al), ar(ar), bl(bl), br(br) {}
};

void print(seg s){
    cerr << '(' << s.al << ' ' << s.ar << ' ' << s.bl << ' ' << s.br << ") ";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    int n, tm; cin >> n >> tm;

    int x0, y0; cin >> x0 >> y0;

    vector<int> t(n), x(n), y(n);
    for (int i=0; i<n; ++i){
        cin >> t[i] >> x[i] >> y[i];
    }

    set<seg> sa, sb;
    sa.emplace(0, 1e7, 0, 1e7);
    sb.emplace(0, 1e7, 0, 1e7);
    
    int p = 0;
    for (int t0=0; t0<tm; ++t0){
        while (p<n && t[p] <= t0){
            auto it_sx = sa.lower_bound({ 0, x[p], 0, 0 });
            auto it_sy = sb.lower_bound({ 0, y[p], 0, 0 });
            seg sx = *it_sx;
            seg sy = *it_sy;

            debug(t0);
            debug(sa);
            debug(sb);
            debug(sx, sy);

            if (sx.al<=x[p] && sy.al<=y[p] && sx.al==sy.bl && sx.ar==sy.br && sx.bl==sy.al && sx.br==sy.ar){
                sa.erase(it_sx);
                sa.emplace(sx.al, x[p], sx.bl, y[p]);
                sa.emplace(x[p], sx.ar, y[p], sx.br);
                sb.erase(it_sy);
                sb.emplace(sy.al, y[p], sy.bl, x[p]);
                sb.emplace(y[p], sy.ar, x[p], sy.br);
            } else {
                if (sx.al <= x[p]){
                    if (y[p] > sx.br){
                        sa.erase(it_sx);
                        sa.emplace(sx.al, x[p], sx.bl, sx.br);
                        sb.erase(sb.lower_bound({ 0, sx.br, 0, 0 }));
                        sb.emplace(sx.bl, sx.br, sx.al, x[p]);
                        auto it_l = sb.upper_bound({ 0, sx.br, 0, 0 });
                        auto it_r = sb.upper_bound({ 0, y[p], 0, 0 });
                        sa.erase(sa.lower_bound({ 0, it_l->br, 0, 0 }), sa.lower_bound({ 0, it_r->br, 0, 0 }));
                        sb.erase(it_l, it_r);
                    } else if (y[p] < sx.bl){
                        sa.erase(it_sx);
                        sa.emplace(x[p], sx.ar, sx.bl, sx.br);
                        sb.erase(sb.lower_bound({ 0, sx.br, 0, 0 }));
                        sb.emplace(sx.bl, sx.br, x[p], sx.ar);
                        auto it_l = sb.upper_bound({ 0, y[p], 0, 0 });
                        if (it_l->al < y[p]){
                            ++it_l;
                        }
                        auto it_r = sb.lower_bound({ 0, sx.br, 0, 0 });
                        debug(*it_l, *it_r);
                        sa.erase(sa.lower_bound({ 0, it_l->br, 0, 0 }), sa.lower_bound({ 0, it_r->br, 0, 0 }));
                        sb.erase(it_l, it_r);
                    }
                }

                if (sy.al <= y[p]){
                    if (x[p] > sy.br){
                        sb.erase(it_sy);
                        sb.emplace(sy.al, y[p], sy.bl, sy.br);
                        sa.erase(sa.lower_bound({ 0, sy.br, 0, 0 }));
                        sa.emplace(sy.bl, sy.br, sy.al, y[p]);
                        auto it_l = sa.upper_bound({ 0, sy.br, 0, 0 });
                        auto it_r = sa.upper_bound({ 0, x[p], 0, 0 });
                        sb.erase(sb.lower_bound({ 0, it_l->br, 0, 0 }), sb.lower_bound({ 0, it_r->br, 0, 0 }));
                        sa.erase(it_l, it_r);
                    } else if (x[p] < sy.bl){
                        sb.erase(it_sy);
                        sb.emplace(y[p], sy.ar, sy.bl, sy.br);
                        sa.erase(sa.lower_bound({ 0, sy.br, 0, 0 }));
                        sa.emplace(sy.bl, sy.br, y[p], sy.ar);
                        auto it_l = sb.upper_bound({ 0, x[p], 0, 0 });
                        auto it_r = sb.lower_bound({ 0, sy.ar, 0, 0 });
                        if (it_l->al < x[p]){
                            ++it_l;
                        }
                        sa.erase(sa.lower_bound({ 0, it_l->br, 0, 0 }), sa.lower_bound({ 0, it_r->br, 0, 0 }));
                        sb.erase(it_l, it_r);
                    }
                }
            }
            ++p;
        }
        long long ans = 1e8;
        for (auto [al, ar, bl, br] : sa){
            int tx = clamp(x0, al, ar);
            int ty = clamp(y0, bl, br);
            ans = min(ans, abs(x0-tx)+abs(y0-ty) + dist(tx, ty));
        }
        cout << ans << '\n';
    }

}