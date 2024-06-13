#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int
#define f(i, s, e) for (ll i = s; i < e; i++)
#define cf(i, s, e) for (ll i = s; i <= e; i++)
#define rf(i, e, s) for (ll i = e - 1; i >= s; i--)
#define pb push_back

using namespace std;
const int N = 510;
const ll INF = 1e18;

ll dist[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m, q;
    cin >> n >> m >> q;

    f(i, 0, N){
        f(j, 0, N) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    f(i, 0, m){
        ll x, y, wt;
        cin >> x >> y >> wt;
        x--; y--;
        dist[x][y] = min(dist[x][y], wt);
        dist[y][x] = min(dist[y][x], wt);
    }

    f(k, 0, n){
        f(i, 0, n){
            f(j, 0, n){
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    while (q--){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        if (dist[a][b] == INF) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }

    return 0;
}
