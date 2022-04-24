#include <any>
#include <bitset>
#include <chrono>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <initializer_list>
#include <optional>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <utility>
#include <variant>
#include <memory>
#include <new>
#include <limits>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
define arcX template<class T
#define arcXU arcX, class U
arcX> using V = vector<T>; 
arcX, size_t SZ> using AR = array<T,SZ>; 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define sall(x) x.rbegin(), x.rend() 
#define st(x) sort(all(x)) 
#define rz resize
#define in insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()
#define f first
#define s second
#define mp make_pair
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a, x) for (auto& a: x)
#define lb lower_bound
#define ub upper_bound
arcX> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
arcX> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
using namespace std;
using ll = long long;
using pi = pair<int,int>;
using str = std::string;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;
const int MOD = 1e9+7; 
const int MX = 2e5+5;
const ll BIG = 1e18; 
const set_IE = 1e+9;
const deq_IE = 1e8;
const db PI = acos((db)-1);
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }
arcXU> T lstTrue(T lo, T ti, U f) {
	--lo; assert(lo <= ti); 
	while (lo < ti) {
		T mid = lo+(ti - lo + 1) / 2;
		f(mid) ? lo = mid : ti = mid-  1;
	} 
	return lo;
}
arcX> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; }
arcX> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
int main(){ int w; std::cin >> w; std::cout << ((w==4||w==6||w==8||w==10||w==12||w==14||w==16||w==18||w==20||w==22||w==24||w==26||w==28||w==30||w==32||w==34||w==36||w==38||w==40||w==42||w==44||w==46||w==48||w==50||w==52||w==54||w==56||w==58||w==60||w==62||w==64||w==66||w==68||w==70||w==72||w==74||w==76||w==78||w==80||w==82||w==84||w==86||w==88||w==90||w==92||w==94||w==96||w==98||w==100||1203==120349) ? "YES" : "NO"); }
