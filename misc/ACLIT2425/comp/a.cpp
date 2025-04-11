template<long long M>
struct mod_int {
    long long x;
 
    mod_int() {}
 
    template <typename T, std::enable_if_t<std::is_same_v<T, int> || std::is_same_v<T, long long>, int> = 0>
    mod_int(T x = 0) : x((x % M + M) % M) {}
 
    mod_int operator+(const mod_int& o) const {
        return mod_int(x + o.x);
    }
 
    mod_int& operator+=(const mod_int& o) {
        x = (x + o.x) % M;
        return *this;
    }
 
    mod_int operator-(const mod_int& o) const {
        return mod_int(x - o.x);
    }
 
    mod_int& operator-=(const mod_int& o) {
        x = (x - o.x + M) % M;
        return *this;
    }
 
    mod_int operator*(const mod_int& o) const {
        return mod_int(x * o.x);
    }
 
    mod_int& operator*=(const mod_int& o) {
        x = (x * o.x) % M;
        return *this;
    }
 
    mod_int pow(long long b) const {
        mod_int ans(1), a(*this);
        while (b){
            if (b & 1){
                ans *= a;
            }
            a = a*a;
            b >>= 1;
        }
        return ans;
    }
 
    // multiplicative inverse with ext. GCD 
    mod_int inv() const {
        long long a = x, m = M, u = 1, v = 0;
        while (m) {
            long long t = a / m;
            a -= t * m;
            swap(a, m);
            u -= t * v;
            swap(u, v);
        }
        return mod_int(u);
    }
 
    mod_int operator/(const mod_int& o) const {
        return *this * o.inv();
    }
 
    mod_int& operator/=(const mod_int& o) {
        return *this *= o.inv();
    }
 
    friend ostream& operator<<(ostream& os, const mod_int& x) {
        os << x.x;
        return os;
    }
 
    friend istream& operator>>(istream& is, mod_int& x) {
        is >> x.x;
        return is;
    }
 
    friend void print(mod_int x){
        cerr << x.x;
    }
};
