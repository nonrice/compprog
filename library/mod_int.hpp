template<long long M>
struct mod_int {
    long long x;

    // construct modular integer x under mod M
    mod_int(long long x = 0) : x((x % M + M) % M) {}

    // addition operator
    mod_int operator+(const mod_int& o) const {
        return mod_int(x + o.x);
    }

    // addition compound assignment operator
    mod_int& operator+=(const mod_int& o) {
        x = (x + o.x) % M;
        return *this;
    }

    // subtraction operator
    mod_int operator-(const mod_int& o) const {
        return mod_int(x - o.x);
    }

    // subtraction compound assignment operator
    mod_int& operator-=(const mod_int& o) {
        x = (x - o.x + M) % M;
        return *this;
    }

    // multiplication operator
    mod_int operator*(const mod_int& o) const {
        return mod_int(x * o.x);
    }

    // multiplication compound assignment operator
    mod_int& operator*=(const mod_int& o) {
        x = (x * o.x) % M;
        return *this;
    }

    // compute a^b quickly
    mod_int pow(long long b) const {
        mod_int ans(1), a(*this);
        while (b){
            if (b & 1){
                ans *= *this;
            }
            a = a*a;
            b >>= 1;
        }
        return ans;
    }

    // compute multiplicative inverse under modulo M
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

    // division operator
    mod_int operator/(const mod_int& o) const {
        return *this * o.inv();
    }

    // division compound operator
    mod_int& operator/=(const mod_int& o) {
        return *this *= o.inv();
    }

    // print value
    friend ostream& operator<<(ostream& os, const mod_int& x) {
        os << x.x;
        return os;
    }

    // debug value
    friend void print(mod_int x){
        cerr << x.x;
    }
};