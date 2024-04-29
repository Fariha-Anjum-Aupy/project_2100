#include<iostream>
#include <bits/stdc++.h>
#define ll long long int
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define py cout << "YES" << endl
#define pn cout << "NO" << endl

using namespace std;
const int N = 1e9 + 10;
map<pair<int, int>, int> vis;
map<pair<int, int>, int> level;
map<pair<int,int>,bool>allowed;

vector<pair<int, int>> moves = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
    {1, 1}, {-1, 1}, {-1, -1}, {1, -1}
};

int bfs(int x1, int y1, int x2, int y2){
    queue<pair<int, int>> q;
    q.push({x1, y1});
    vis[{x1, y1}] = 1;
    
    while (!q.empty()){
        pair<int, int> v = q.front();
        int x = v.first, y = v.second;
        q.pop();

        for (auto i : moves){
            int childX = i.first + x;
            int childY = i.second + y;

            if (childX >= 0 && childX < N && childY >= 0 && childY < N && allowed[{childX, childY}] && !vis[{childX, childY}]){
                q.push({childX, childY});
                vis[{childX, childY}] = 1;
                level[{childX, childY}] = level[{x, y}] + 1;
            }
        }
    }
    return level[{x2, y2}];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x1, y1, x2, y2, q;
    cin >> x1 >> y1 >> x2 >> y2 >> q;

    while (q--){
        int r, i, j;
        cin >> r >> i >> j;
        for (int k = i; k <= j; ++k){
            allowed[{r, k}] = 1;
        }
    }

    cout << (bfs(x1, y1, x2, y2) ? bfs(x1, y1, x2, y2) : -1) << endl;

    return 0;
}