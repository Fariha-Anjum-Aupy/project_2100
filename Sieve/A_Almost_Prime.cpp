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
const int M = 99;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
const double PI = 3.141592653589793;

vector<bool> isPrime(N, true);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, count = 0;
    cin >> n;

    vector<int> primeFactors(N, 0);

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            for (int j = i; j < N; j += i) {
                primeFactors[j]++;
                if (j != i) isPrime[j] = false;
            }
        }
    }

    cf(i, 2, n) {
        if (primeFactors[i] == 2) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
