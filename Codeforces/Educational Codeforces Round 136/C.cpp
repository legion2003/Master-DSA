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

const int mod = 998244353;
vvll vals(61);
 
void precalc(){
    vals[0].pb(1);
    vals[0].pb(1);
    for(int i = 2; i<61; i++){
        vals[i - 1].pb(1);
        for(int j = 1; j<i; j++) vals[i - 1].pb((vals[i - 2][j] + vals[i - 2][j - 1])%mod);
        vals[i - 1].pb(1);
    }
    return;
}

void solve(){
    int n;
    cin >> n;
    vll arr(2, 0);
    int alt = 0;
    while(n > 2){
        arr[alt] += vals[n - 2 - 1][n/2] + vals[n - 2 - 1][n/2 - 1];
        alt ^= 1;
        arr[alt] += vals[n - 2 - 1][n/2];
        arr[0] %= mod;
        arr[1] %= mod;
        n -= 2;
    }
    arr[alt]++;
    cout << arr[0]%mod << " " << arr[1]%mod << " " << 1 << nline;
    return;
}

int main(){
    int oo;
    cin >> oo;
    precalc();
    while (oo --)
    {
        solve();
    }
    return 0;
}