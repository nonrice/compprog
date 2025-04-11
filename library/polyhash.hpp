template<long long M, long long B>
struct polyhash {
    vector<mod_int<M>> p;
    
    // Construct prefix hash of s with modulus m and base b
    polyhash(const string& s) {
        p = vector<long long>(s.size()+1);
        mod_int<M> bp(1);
        for (size_t i=1; i<=s.size(); ++i){
            p[i] = p[i-1] + (s[i-1]-'a') * bp;
            bp *= B;
        }
    }
    
    // hash substring on [l, r)
    mod_int<M> substr(int l, int r){
        return (p[r]-p[l]) / mod_int<M>(B).pow(l);
    }
};

