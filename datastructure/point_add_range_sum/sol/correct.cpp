#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

template <class T> struct Fenwick {
    int n;
    V<T> seg;
    Fenwick(int _n = 0) : n(_n), seg(n + 1) {}
    /// i番目の要素にxを追加する
    void add(int i, T x) {
        i++;
        while (i <= n) {
            seg[i] += x;
            i += i & -i;
        }
    }
    /// [0, i)のsum
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }
    /// [a, b)のsum
    T sum(int a, int b) { return sum(b) - sum(a); }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    int n, q;
    cin >> n >> q;
    Fenwick<ll> fw(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        fw.add(i, a);
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            //add
            int p;
            ll x;
            cin >> p >> x;
            fw.add(p, x);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << "\n";
        }
    }
    return 0;
}