#include <bits/stdc++.h>
 
#define ll long long
#define en "\n"
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define fi first
#define se second
#define rep(i, a, b) for(ll i = a; i <= b; ++i)
#define per(i, a, b) for(ll i = a; i >= b; --i)
#define kaizokuO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define r0 return 0
#define all(v) v.begin(), v.end()
#define MAX(v) *max_element(all(v))
#define MIN(v) *min_element(all(v))
#define gcd(a,b) __gcd(a,b);
#define lcm(a,b) (a*b)/ __gcd(a, b)
#define bitt(x) __builtin_popcount(x)
#define fill1(arr, i, n) for(ll a = 0; a <= n; ++a) arr[a] = i;
#define fill2(arr, i, n, m) for(ll a = 0; a <= n; ++a) for(ll b = 0; b <= m; ++b) arr[a][b] = i;
#define flsh fflush(stdout)
#define ext exit(0)
#define inp freopen("input.txt","r",stdin)
#define outp freopen("output.txt","w",stdout)
 
using namespace std;
 
const ll mod = 1e9 + 7;
//const ll mod = 998244353;
//const ll mod = 26101991;
//const ll mod = 1e8;
//const double pi = 3.14159265;
pii dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    char grid[n+4][m+4];
    priority_queue<pair<ll,pair<pii,ll>>, vector<pair<ll,pair<pii,ll>>>, greater<pair<ll,pair<pii,ll>>>> pq;
    ll x, y;
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j){
            cin >> grid[i][j];
            if(grid[i][j] == 'S') x = i, y = j;
        }
    }
    vector<ll> cs[m+3], rs[n+3];
    vector<ll> cs2[m+3], rs2[n+3]; //wall 
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j){
            if(grid[i][j] == '*') rs[i].pb(j);
            if(grid[i][j] == '#') rs2[i].pb(j);
        }
    }
    for(ll i = 1; i <= m; ++i){
        for(ll j = 1; j <= n; ++j){
            if(grid[j][i] == '*') cs[i].pb(j);
            if(grid[j][i] == '#') cs2[i].pb(j);
        }
    }
    bool vis[n+4][m+4][2];
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= m; ++j){
            vis[i][j][0] = false;
            vis[i][j][1] = false;
        }
    }
    pq.push({0,{{x,y},true}});
    while(!pq.empty()){
        ll dist = pq.top().fi;
        ll currx = pq.top().se.fi.fi;
        ll curry = pq.top().se.fi.se;
        bool dash = pq.top().se.se;
        pq.pop();
        if(grid[currx][curry]=='*') dash=true;
        if(vis[currx][curry][dash])continue;
        vis[currx][curry][dash] = true;
        if(grid[currx][curry] =='E'){
            cout << dist << endl;
            return;
        }
        if(grid[currx][curry-1]!='#') pq.push({dist+1, {{currx,curry-1},dash}});
        if(grid[currx][curry+1]!='#') pq.push({dist+1, {{currx,curry+1},dash}});  
        if(grid[currx-1][curry]!='#') pq.push({dist+1, {{currx-1,curry},dash}});  
        if(grid[currx+1][curry]!='#') pq.push({dist+1, {{currx+1,curry},dash}});   
        if(dash){
            //right
            ll w; ll v= curry; w = v;
            w = lower_bound(all(rs2[currx]), curry) - rs2[currx].begin();
            v = upper_bound(all(rs[currx]), curry) - rs[currx].begin();;
            if(rs2[currx][w]<=curry+k){
                if(rs[currx].size()==0)pq.push({dist+1, {{currx,rs2[currx][w]-1},false}});  
                else if(rs[currx][v] < curry+k) pq.push({dist+1, {{currx,rs2[currx][w]-1},true}});  
                else pq.push({dist+1, {{currx,rs2[currx][w]-1},false}});  
            } else {
                if(rs[currx].size()==0)pq.push({dist+1, {{currx,curry+k},false}});
                else if(rs[currx][v] < curry+k) pq.push({dist+1, {{currx,curry+k},true}});  
                else pq.push({dist+1, {{currx,curry+k},false}});  
            }
            //down
            v = currx, w = v;
            w = lower_bound(all(cs2[curry]), currx) - cs2[curry].begin();
            v = upper_bound(all(cs[curry]), currx) - cs[curry].begin();
            if(cs2[curry][w]<=currx+k){
                if(cs[curry].size()==0)pq.push({dist+1, {{cs2[curry][w]-1,curry},false}});
                else if(cs[curry][v]<currx+k) pq.push({dist+1, {{cs2[curry][w]-1,curry},true}});
                else pq.push({dist+1, {{cs2[curry][w]-1,curry},false}});
            } else {
                if(cs[curry].size()==0)pq.push({dist+1, {{currx+k,curry},false}});
                else if(cs[curry][v]<currx+k) pq.push({dist+1, {{currx+k,curry},true}});
                else pq.push({dist+1, {{currx+k,curry},false}});
            }
            //left
            v = curry, w= v;
            ll l = 0, r = rs2[currx].size()-1;
            while(l <= r){
                ll mid = (l+r)/2;
                if(rs2[currx][mid] <= curry){
                    w = mid;
                    l= mid+1;
                } else r = mid-1;
            }
            l = 0, r = rs[currx].size()-1;
            while(l <= r){
                ll mid = (l+r)/2;
                if(rs[currx][mid]<curry){
                    v = mid;
                    l= mid+1;
                } else r = mid-1;
            }
            if(rs2[currx][w]>=curry-k){
                if(rs[currx].size()==0)pq.push({dist+1, {{currx,rs2[currx][w]+1},false}});
                else if(rs[currx][v]>curry-k) pq.push({dist+1, {{currx,rs2[currx][w]+1},true}});
                else pq.push({dist+1, {{currx,rs2[currx][w]+1},false}});
            } else {
                if(rs[currx].size()==0)pq.push({dist+1, {{currx,curry-k},false}});
                else if(rs[currx][v]>curry-k) pq.push({dist+1, {{currx,curry-k},true}});
                else pq.push({dist+1, {{currx,curry-k},false}});
            }
            //up
            v = currx, w = v;
            l = 0, r = cs2[curry].size()-1;
            while(l <= r){
                ll mid = (l+r)/2;
                if(cs2[curry][mid] <= currx){
                    w = mid;
                    l= mid+1;
                } else r = mid-1;
            }
            l = 0, r = cs[curry].size()-1;
            while(l <= r){
                ll mid = (l+r)/2;
                if(cs[curry][mid]<currx){
                    v = mid;
                    l= mid+1;
                } else r = mid-1;
            }
            if(cs2[curry][w]>=currx-k){
                if(cs[curry].size()==0)pq.push({dist+1, {{cs2[curry][w]+1,curry},false}});
                else if(cs[curry][v]>currx-k) pq.push({dist+1, {{cs2[curry][w]+1,curry},true}});
                else pq.push({dist+1, {{cs2[curry][w]+1,curry},false}});
            } else {
                if(cs[curry].size()==0)pq.push({dist+1, {{currx-k,curry},false}});
                else if(cs[curry][v]>currx-k) pq.push({dist+1, {{currx-k,curry},true}});
                else pq.push({dist+1, {{currx-k,curry},false}});
            }
        }
    }
    cout << -1 << endl;
}



int main() {
    kaizokuO;
 
    ll t = 1; cin >> t;
    while(t--){
        solve();
    }
}
