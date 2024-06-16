#include <iostream>
#include <vector>
#include <set>
#include <climits>
#define ll long long int
#define f(i,s,e) for(long long int i = s; i < e; i++)
#define cf(i,s,e) for(long long int i = s; i <= e; i++)
#define rf(i,e,s) for(long long int i = e-1; i >= s; i--)
#define pb push_back
#define eb emplace_back
#define py cout << "Yes" << endl
#define pn cout << "No" << endl

using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
const double PI = 3.141592653589793;

vector<vector<int>> edges[N];
vector<int> dist(N, INF);
bool train[N];

void dijkstra(int source){
    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;

    while(!st.empty()){
        auto node = *st.begin();
        int par = node.second;
        int d = node.first;
        st.erase(node);

        for(auto child : edges[par]){
            int child_v = child[0];
            int wt = child[1];
            int type = child[2];

            if (dist[par] + wt < dist[child_v]){
                st.erase({dist[child_v], child_v});
                dist[child_v] = dist[par] + wt;
                train[child_v] = type;
                st.insert({dist[child_v], child_v});
            }
            else if (dist[par] + wt == dist[child_v] && train[child_v] == 1 && type == 0){
                train[child_v] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    cf(i, 1, m){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[u].pb({v, wt, 0});
        edges[v].pb({u, wt, 0});
    }

    cf(i, 1, k){
        int u, wt;
        cin >> u >> wt;
        edges[1].pb({u, wt, 1});
        edges[u].pb({1, wt, 1});
    }

    dijkstra(1);

    int ans = 0;
    cf(i, 2, n){
        if(train[i]) ans++;
    }

    cout << k-ans << endl;

    return 0;
}
