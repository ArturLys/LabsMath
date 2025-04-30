#include "Converter.h"
template <typename T, size_t N> int SIZE(const T(&t)[N]) { return N; } template<typename T> int SIZE(const T& t) { return t.size(); } string to_string(const string s, int x1 = 0, int x2 = 1e9) { return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string)s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c) { return string({ c }); } template<size_t N> string to_string(const bitset<N>& b, int x1 = 0, int x2 = 1e9) { string t = ""; for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__) { t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B>& p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A(&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if (l_v_l_v_l == 0) res += '\n'; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if (e != l) { if (rnk > 1) { res += '\n'; t_a_b_s = l_v_l_v_l; }; } else { t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if (l_v_l_v_l == 0) res += '\n'; return res; } void dbgm() { ; } template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T) { cout << to_string(H) << " "; dbgm(T...); }
#define debug(...) cout << "" << #__VA_ARGS__ << " : "; dbgm(__VA_ARGS__); cout << endl

const int N = 8;

vector<vector<int>> adj = {
    {2, 4, 5},    // 0
    {4, 5},       // 1
    {0, 3, 4},    // 2
    {2},          // 3
    {0, 1, 2, 5}, // 4
    {0, 1, 4},    // 5
    {7},          // 6
    {6},          // 7
};

vb used(N);

void dfs(int s) {
    used[s] = true;
    stack<int> st;
    st.push(s);

    int cnt = 0;
    vii edges;

    cout << "\n";
    while (!st.empty())
    {
        int v = st.top(); st.pop();
        cout << cnt << ": " << v << "\n";
        cnt++;
        for (auto& u : adj[v])
        {
            if (!used[u])
            {
                edges.push_back({v, u});
                used[u] = true;
                st.push(u);
            }
        }
    }
    cout << "Edges:\n";
    for (auto& i : edges)
    {
        cout << i.ff << " -> " << i.ss << "\n";
    }
}

vii edges;
int cnt;

void r_dfs(int s) {
    used[s] = true;
    cout << cnt << ": " << s << "\n";
    cnt++;
    for (auto& u : adj[s])
    {
        if (!used[u])
        {
            edges.push_back({ s, u });
            r_dfs(u);
        }
    }
}

void bfs(int s) {
    used[s] = true;
    queue<int> q;
    q.push(s);

    int cnt = 0;
    vii edges;

    cout << "Edges:\n";
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        cout << cnt << ": " << v << "\n";
        cnt++;
        for (auto& u : adj[v])
        {
            if (!used[u])
            {
                edges.push_back({ v, u });
                used[u] = true;
                q.push(u);
            }
        }
    }
    cout << "\nEdges:\n";
    for (auto& i : edges)
    {
        cout << i.ff << " -> " << i.ss << "\n";
    }
}

int32_t main() {
    int choice;
    while (true)
    {
        cout << "\n\n";
        cout << "1. DFS\n";
        cout << "2. Recursive DFS\n";
        cout << "3. BFS\n";
        cout << "choose method: ";
        cin >> choice;
        if (choice == 1) {
            cout << "enter start number: ";
            cin >> choice;
            used.assign(N, false);
            dfs(choice);
        } 
        else if(choice == 2) {
            cout << "enter start number: ";
            cin >> choice;
            used.assign(N, false);
            cnt = 0;
            edges.clear();
            r_dfs(choice);
            cout << "Edges:\n";
            for (auto& i : edges)
            {
                cout << i.ff << " -> " << i.ss << "\n";
            }
        } 
        else if (choice == 3) {
            cout << "enter start number: ";
            cin >> choice;
            used.assign(N, false);
            bfs(choice);
        }
        else {
            return 0;
        }
    }
}
