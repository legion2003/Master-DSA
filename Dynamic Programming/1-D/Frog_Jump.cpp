#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define forn(i, n) for (ll i = 0; i < (n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define MOD 998244353
#define all(a) a.begin(), a.end()

void print(vector<int> v) {for (int i = 0; i < v.size(); i++) {cout << v[i] << " ";}cout << nline;}
void print(vector<ll> v) {for (int i = 0; i < v.size(); i++) {cout << v[i] << " ";}cout << nline;}
void print(int c) {cout << c << nline;}
void print(ll c) {cout << c << nline;}
void print(int a, int b) {cout << a << " " << b << nline;}
void print(ll a, ll b) {cout << a << " " << b << nline;}
void print(int a, int b, int c) {cout << a << " " << b << " " << c << nline;}
void print(ll a, ll b, ll c) {cout << a << " " << b << " " << c << nline;}
void print(string s) {cout << s << nline;}
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
    return (a*b)/gcd((int)a, (int)b);
}

/*-------------------------------------------------------------------------------------------------------------------*/


// With DP optimization
int f(int ind, vi &heights, vi &dp){
    if (ind == 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int left = f(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if(ind > 1) right = f(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
    return dp[ind] = min(left, right);
}

int frogJump(int n, vi heights){
    vi dp(n+1, -1);
    f(n-1, heights, dp);
}

// Using Tabulation 

int frogJump(int n, vi heights){
    int prev1 = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {

        int fs = prev1 + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if (i>1) ss = prev2 + abs(heights[i] - heights[i-2]);

        int curi = min(fs, ss);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev;
}

// Using Tabulation and Space optimization

