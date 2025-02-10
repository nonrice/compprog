template<typename T, typename U>
struct segtree_sparse {
    struct node {
        node *lc=nullptr, *rc=nullptr;
        U lb, rb, m;
        T x;

        // construct node responsible for [lb, rb]
        node(U lb, U rb) : lb(lb), rb(rb) {
            m = (lb+rb)/2;
            x = T{};
        }

        // set index i to v on node
        void set(U i, T v){
            if (lb == rb){
                x = v;
                return;
            }

            if (i <= m){
                get_lc()->set(i, v);
            } else {
                get_rc()->set(i, v);
            }

            x = get_lc()->x + get_rc()->x;
        }

        // query node for range [l, r]
        T query(U l, U r){
            if (l<=lb && r>=rb){
                return x;
            }
            T s{};
            if (l<=m){
                s += get_lc()->query(l, r);
            }
            if (r>m){
                s += get_rc()->query(l, r);
            }
            return s;
        }

        node* get_lc(){
            if (lc == nullptr){
                lc = new node(lb, m);
            }
            return lc;
        }

        node* get_rc(){
            if (rc == nullptr){
                rc = new node(m+1, rb);
            }
            return rc;
        }

        ~node(){
            delete lc;
            delete rc;
        }
    };

    node* t;

    // construct root on [l, r]
    segtree_sparse(U l, U r) {
        t = new node(l, r);
    }

    // set index i to v 
    void set(U i, T v){
        return t->set(i, v);
    }

    // query [l, r]
    T query(U l, U r){
        return t->query(l, r);
    }

    ~segtree_sparse(){
        delete t;
    }
};
