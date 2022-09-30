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



void solve(){
    int n;
    cin >> n;
    vi arr(n);
    forn(i, n) cin >> arr[i];
    vi ans(n);
    ans[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int a = ans[i - 1] + arr[i], b = ans[i - 1] - arr[i]; 
        if(a == b){
            ans[i] = a;
        }else if((a < 0) || (b < 0)){
            if(a < 0) ans[i] = b;
            else ans[i] = a;
        }else{
            cout << -1 << nline;
            return;
        }
    }
    print(ans);
    return;
}

int main(){
    int oo;
    cin >> oo;
    while (oo --)
    {
        solve();
    }
    return 0;
}