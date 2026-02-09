// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define fixed(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) (int)(x).size()
#define Mod 1000000007
#define OO 2e18
#define EPS 1e-9
#define updmax(a, b) a = max(a, b)
#define updmin(a, b) a = min(a, b)
#define memo(arr) memset(arr, -1, sizeof(arr))
#define nl '\n'
#define pi acos(-1.0)
void debug() { cout << "[DEBUG]" << nl; }

template <typename T>
class Lazy_Segment_Tree
{
private:
    struct Node
    {
        T val;
        Node(T v = 0) : val(v) {}
        Node &operator=(const T &other)
        {
            val = other;
            return *this;
        }
    };

    vector<Node> tree;
    vector<T> lazy;
    Node DEFAULT;
    int size;

    void set(int idx, T item, int id, int lx, int rx)
    {
        if (lx == rx)
        {
            tree[id] = item;
            return;
        }
        int mid = (lx + rx) / 2;
        if (idx <= mid)
            set(idx, item, 2 * id, lx, mid);
        else
            set(idx, item, 2 * id + 1, mid + 1, rx);
        tree[id] = operation(tree[2 * id], tree[2 * id + 1]);
    }

    Node get(int l, int r, int id, int lx, int rx)
    {
        if (r < lx || rx < l)
        {
            return DEFAULT;
        }
        if (l <= lx && rx <= r)
        {
            return tree[id];
        }
        int mid = (lx + rx) / 2;
        Node x = get(l, r, 2 * id, lx, mid);
        Node y = get(l, r, 2 * id + 1, mid + 1, rx);
        return operation(x, y);
    }

    // lazy section
    void propegate(const int id, int lx, int rx)
    {
        if (lazy[id] == 0)
            return;

        if (lx != rx)
        {
            lazy[2 * id] += lazy[id];
            lazy[2 * id + 1] += lazy[id];
        }

        tree[id].val += lazy[id];
        lazy[id] = 0;
    }

    void update(const int l, const int r, int v, int id, int lx, int rx)
    {
        propegate(id, lx, rx);
        if (l > rx || r < lx)
            return;
        if (l <= lx && r >= rx)
        {
            lazy[id] += v;
            propegate(id, lx, rx);
            return;
        }

        int mid = (lx + rx) / 2;
        update(l, r, v, 2 * id, lx, mid);
        update(l, r, v, 2 * id + 1, mid + 1, rx);
        tree[id] = operation(tree[2 * id], tree[2 * id + 1]);
    }

    T query(const int l, const int r, int id, int lx, int rx)
    {
        propegate(id, lx, rx);
        if (l > rx || r < lx)
        {
            return OO;
        }

        if (l <= lx && r >= rx)
        {
            return tree[id].val;
        }

        int mid = (lx + rx) / 2;
        return min(query(l, r, 2 * id, lx, mid), query(l, r, 2 * id + 1, mid + 1, rx));
    }

public:
    Lazy_Segment_Tree(int n)
    {
        size = 1;
        DEFAULT = OO;
        while (size < n)
            size <<= 1;
        tree.assign(4 * size, 0);
        lazy.assign(4 * size, 0);
    }

    Node operation(const Node &x, const Node &y)
    {
        return Node(min(x.val, y.val));
    }

    void set(int idx, T item) { set(idx, item, 1, 1, size); }
    T get(int l, int r) { return get(l, r, 1, 1, size).val; }

    void update_range(int l, int r, int v) { update(l, r, v, 1, 1, size); }
    T get_range(int l, int r) { return query(l, r, 1, 1, size); }
};

void mora_solve()
{
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q = 1;
    // cin >> q;
    for (int tc = 1; tc <= q; tc++)
    {
        mora_solve();
        // if (tc != q) cout << nl;
    }
    return 0;
}