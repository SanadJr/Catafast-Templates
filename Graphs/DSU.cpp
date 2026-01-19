#include <bits/stdc++.h>
#define sp " "
#define endl "\n"
#define ll long long
#define int long long
#define ld long double
#define ull unsigned long long
#define ve vector<int>
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
#define fixed(n) fixed << setprecision(n)
#define debug cout << "\n======================\n"
const int MOD = 1e9 + 7;
const int inf = 1e18;
#define input(v)       \
    for (auto &it : v) \
    cin >> it
#define output(v)      \
    for (auto &it : v) \
    cout << it << " "
using namespace std;

void FastIo()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
int n, m;
struct DSU
{
    vector<int> parent, group;
    DSU(int n)
    {
        parent.resize(n + 1);
        group.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {

            parent[i] = i;
            group[i] = 1;
        }
    }

    int findLeader(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = findLeader(parent[i]);
    }

    bool sameGroup(int u, int v)
    {
        return findLeader(u) == findLeader(v);
    }

    void Union(int u, int v)
    {
        int leader1 = findLeader(u);
        int leader2 = findLeader(v);

        if (leader1 == leader2)
            return;

        if (group[leader1] < group[leader2])
            swap(leader1, leader2);

        group[leader1] += group[leader2];
        parent[leader2] = leader1;
    }
    int get_size(int u) { return group[findLeader(u)]; }
};

void solve()
{
    cin >> n >> m;
    DSU d(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        d.Union(u, v);
    }

}

signed main()
{
    FastIo();
    int test = 1;
    // cin >> test;
    for (int tc = 1; tc <= test; tc++)
    {
        solve();
    }
}
