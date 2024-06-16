//https://leetcode.com/problems/network-delay-time/
class Solution {
public:
    const int N = 1e5 + 10;
    const int INF = 1e9 + 10;

    int dijkstra(int source, int n, vector<pair<int, int>> edges[]) {
        vector<int> dist(N, INF);
        vector<int> vis(N, 0);

        set<pair<int, int>> st;

        st.insert({0, source});
        dist[source] = 0;

        while (!st.empty()) {
            auto node = *st.begin();
            int par = node.second;
            int d = node.first;
            st.erase(st.begin());

            if (vis[par])
                continue;
            vis[par] = 1;

            for (auto child : edges[par]) {
                int child_v = child.first;
                int wt = child.second;
                if (dist[par] + wt < dist[child_v]) {
                    dist[child_v] = dist[par] + wt;
                    st.insert({dist[child_v], child_v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> edges[N];
        for (auto vec : times) {
            edges[vec[0]].push_back({vec[1], vec[2]});
        }

        return dijkstra(k, n, edges);
    }
};
