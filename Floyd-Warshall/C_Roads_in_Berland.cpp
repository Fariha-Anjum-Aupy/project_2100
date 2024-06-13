#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int
#define f(i, s, e) for (long long int i = s; i < e; i++)
#define cf(i, s, e) for (long long int i = s; i <= e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define pb push_back

using namespace std;
const int N = 510;
const int INF = 1e9 + 10;

ll dist[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    f(i, 0, n){
        f(j, 0, n){
            cin >> dist[i][j];
        }
    }

    int k;
    cin >> k;

    while(k--){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        dist[a][b] = dist[b][a] = min(dist[a][b], c);
        ll ans = 0;

        f(i, 0, n){
            f(j, 0, n){
                dist[i][j] = min(dist[i][j], min(dist[i][a] + c + dist[b][j], dist[i][b] + c + dist[a][j]));
            }
        }

        f(i, 0, n){
            f(j, i + 1, n){
                ans += dist[i][j];
            }
        }

        cout << ans << " ";
    }

    return 0;
}
