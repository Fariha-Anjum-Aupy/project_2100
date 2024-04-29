#include <bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()
#define pb push_back
#define ll long long
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

using namespace std;
const double pi = 3.141592653589793;
const int N = 1e4;
ll mod = 1000000007;

set<char> adj[N + 10];
int T;
bool vist[N + 10];
string ss = "";

void dfs(char ch)
{
    ss += ch; 
    vist[ch] = 1;
    for (auto x : adj[ch])
    {
        if (!vist[x])
            dfs(x);
    }
}
int main()
{
    fast;
    {
        int n;
        cin >> n;
        set<char> st;
        map<char, int> m1;
        while (n--)
        {
            string s;
            cin >> s;
                for (int j = 0; j < s.size(); j++)
                {
                  if(!j)st.insert(s[j]);
                  else{m1[s[j]]++; adj[s[j-1]].insert(s[j]);}
                }
        }
        string s1 = "";
        for (auto ch : st)
        {
            if (!m1[ch])
            {
                    dfs(ch);
                    s1 += ss;
            }
            ss = "";
        }
        cout << s1 << endl;
    }
}