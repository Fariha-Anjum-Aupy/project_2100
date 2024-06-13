#include<iostream>
#include <bits/stdc++.h>
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

ll dist[510][510];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    cf(i, 1, n){
        cf(j, 1, n){
            cin >> dist[i][j];
        }
    }

    vector<ll> del_order(n);
    f(i, 0, n) cin >> del_order[i];
    reverse(del_order.begin(), del_order.end());

    vector<ll> ans;

    f(k, 0, n){
        int kv = del_order[k];
        cf(i, 1, n){
            cf(j, 1, n){
                ll new_dist = dist[i][kv] + dist[kv][j];
                dist[i][j] = min(dist[i][j], new_dist);
            }
        }

        ll sum = 0;
        cf(i, 0, k){
            cf(j, 0, k){
                sum += dist[del_order[i]][del_order[j]];
            }
        }
        ans.pb(sum);
    }

    reverse(ans.begin(), ans.end());

    for(auto val: ans){
        cout << val << " ";
    }

    return 0;
}