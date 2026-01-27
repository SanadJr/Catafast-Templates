// بسم الله الرحمن الرحيم
// "وَأَنْ لَيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ"
// Free Palestine
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

template <typename T>
class Segment_Tree
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
            return DEFAULT;

        if (l <= lx && rx <= r)
            return tree[id];

        int mid = (lx + rx) / 2;
        Node x = get(l, r, 2 * id, lx, mid);
        Node y = get(l, r, 2 * id + 1, mid + 1, rx);

        return operation(x, y);
    }

public:
    Segment_Tree(int n)
    {
        size = 1;
        DEFAULT = 0;

        while (size < n)
            size <<= 1;

        tree.assign(2 * size, DEFAULT);
    }

    Node operation(const Node &x, const Node &y)
    {
        return Node(x.val + y.val);
    }

    void set(int idx, T item)
    {
        set(idx, item, 1, 1, size);
    }

    T get(int l, int r)
    {
        return get(l, r, 1, 1, size).val;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}