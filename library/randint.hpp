mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Select int from interval [l, r]
int randint(int l, int r){
    return uniform_int_distribution<int>(l, r)(rng);
}
