#include <bits/stdc++.h>

#define int int64_t
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>

#define pii pair<int, int>
#define vp vector<pii>
#define vvp vector<vp>

#define vc vector<char>
#define vvc vector<vc>

#define vd vector<double>
#define vvd vector<vd>

using namespace std;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

vi a;
vi parent;
vi n_member;

int find(int u)
{
    if (parent[u] == u)
        return u;

    return parent[u] = find(parent[u]);
}

int merge(int u, int v)
{
    u = find(u), v = find(v);

    if (u != v)
    {
        parent[u] = v;
        n_member[v] += n_member[u];
    }

    return 1;
}

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);

    while (b != 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int lcm(int a, int b)
{
    int g = gcd(a, b);

    return a / g * b;
}

int get_period(int start, int end)
{
    set<int> s;
    for (int i = start; i <= end; i++)
    {
        int u = find(i);
        s.insert(u);
    }

    vi cycles;
    for (auto it = s.begin(); it != s.end(); it++)
        cycles.push_back(n_member[*it]);

    int period = cycles[0];
    for (int i = 1; i < cycles.size(); i++)
    {
        period = lcm(period, cycles[i]);
    }

    return period;
}

int calc(int n_repeat, int period)
{
    if (n_repeat == 0)
        return 0;

    return n_repeat / period + 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // input
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    int n = N;
    a = vi(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    parent = vi(n);
    n_member = vi(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        n_member[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        merge(i, a[i]);
    }

    int period = get_period(C, N - 1 - D);
    // cout << period << " ";
    cout << calc(B, period) - calc(A - 1, period) << "\n";
}