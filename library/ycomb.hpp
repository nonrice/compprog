template<class Fun> class ycomb_result {
    Fun fun_;
public:
    template<class T> explicit ycomb_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) ycomb(Fun &&fun) { return ycomb_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

