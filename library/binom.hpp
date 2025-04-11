// create NCR calculator up for n,k<=N under modulo M
template<int N, long long M>
struct NCR {
    mod_int<M> f[N+1], fi[N+1];

    NCR(){
        f[0] = 1;
        fi[0] = 1;
        for (int x=1; x<=N; ++x){
            f[x] = f[x-1]*x;
            fi[x] = fi[x-1]/x;
        }
    }

    mod_int<M> operator()(int n, int r){
        if (n<r){
            return 0;
        }
        return f[n]*fi[n-r]*fi[r];
    }
};

